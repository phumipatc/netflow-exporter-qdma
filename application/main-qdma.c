#include "parse_cmd.h"
#include "data_manager.h"
#include "db_writer.h"
#include "qdma_fn.h"

#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

/*
    Constants
*/
#define MAX_RECORDS 16777216
#define MAX_RECORDS_SIZE 64
#define MAX_DATA_SIZE MAX_RECORDS * MAX_RECORDS_SIZE

#define SEED 0xA3F7C92D

/* 
    Shared variables between main thread and data processing thread
*/
volatile int shouldExit = 0;
volatile int isNormalDataReady = 0;

int sharedBufferLength = 0;

char sharedBuffer[MAX_DATA_SIZE];

pthread_mutex_t normalDataMutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t normalDataCond = PTHREAD_COND_INITIALIZER;

/*
    Global variables for graceful exit
*/
int fd; // Global file descriptor for graceful exit
int mock_fd; // Global file descriptor for mock data

unsigned int device_id_num;

// Signal handler
void gracefulExit(int sig) {
    int ret;

    printf("Caught signal %d\n", sig);

    shouldExit = 1;

    ret = write_register(device_id_num, 0x8, 0x0);
    if (ret < 0) {
        printf("Error in disabling P4 engine with ret = %d\n", ret);
    }

    pthread_mutex_lock(&normalDataMutex);
    pthread_cond_signal(&normalDataCond);
    pthread_mutex_unlock(&normalDataMutex);

    if (fd >= 0) {
        close(fd);
        printf("File descriptor closed.\n");
    }

    if (mock_fd >= 0) {
        close(mock_fd);
        printf("Mock file descriptor closed.\n");
    }

    printf("Exiting...\n");
    // exit(0);
}

// Helper function to get the current timestamp as a string
void getCurrentTimestamp(char* buffer, size_t bufferSize) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, bufferSize, "%Y%m%d_%H%M%S", t);
}

// Helper function to create directory if it doesn't exist
void ensureDirectoryExists(const char* dirPath) {
    if (mkdir(dirPath, 0777) != 0 && errno != EEXIST) {
        perror("Error creating directory");
        exit(EXIT_FAILURE);
    }
}

void* processNormalData(void* programArgs) {
    program_args_t* args = (program_args_t*)programArgs;
    normal_data_t *normal_data_array = malloc(MAX_RECORDS * sizeof(normal_data_t));

    char filePath[256];
    char normalDirPath[256];
    char separator[] = {0x0D, 0x0A};
    char timestamp[32];
    char *tokenAddress = malloc(MAX_DATA_SIZE * sizeof(char ));
    char **tokens = malloc(MAX_RECORDS * sizeof(char *));
    char *writingBuffer = malloc(MAX_RECORDS * MAX_RECORDS_SIZE);

    int data_len;
    int recordCount;
    int numTokens;
    int ret;

    for(int i = 0; i < MAX_RECORDS; i++) {
        tokens[i] = tokenAddress + i * MAX_RECORDS_SIZE;
    }

    if (args->verbose) {
        printf("Normal data processing thread started\n");
    }

    snprintf(normalDirPath, sizeof(normalDirPath), "%s/normal", args->dir_path);

    // Ensure directories exist
    ensureDirectoryExists(normalDirPath);

    while(!shouldExit) {
        pthread_mutex_lock(&normalDataMutex);

        if(args->verbose) {
            printf("Normal data processing thread waiting for signal\n");
        }
        while (!isNormalDataReady && !shouldExit) {
            pthread_cond_wait(&normalDataCond, &normalDataMutex);
        }

        if (shouldExit) {
            pthread_mutex_unlock(&normalDataMutex);
            break;
        }

        data_len = sharedBufferLength;
        numTokens = 0;

        if (args->verbose) {
            printf("Normal data processing thread processing data of length %d\n", data_len);
        }

        // the separator is array of 2 bytes, 0x0D and 0x0A
        ret = tokenizeData(sharedBuffer, data_len, separator, tokens, &numTokens);
        if (ret < 0) {
            printf("Error in tokenizing data with ret = %d\n", ret);
            continue;
        } else if(args->verbose) {
            printf("Tokenized data into %d tokens\n", numTokens);
        }

        recordCount = 0; // Reset record count for this batch
        for (int i = 0; i < numTokens; ++i) {
            ret = extractNormalData(&normal_data_array[recordCount], tokens[i], strlen(tokens[i]));
            if (ret < 0) {
                printf("Error in extracting normal data with ret = %d\n", ret);
                continue;
            }
            recordCount++;
        }

        if (recordCount > 0) {
            ret = convertArrayOfNormalDataToCSV(normal_data_array, recordCount, writingBuffer);
            if (ret < 0) {
                printf("Error in converting data to CSV\n");
                continue;
            }

            getCurrentTimestamp(timestamp, sizeof(timestamp));
            snprintf(filePath, sizeof(filePath), "%s/data_%s.csv", normalDirPath, timestamp);

            ret = writeToFile(filePath, writingBuffer, strlen(writingBuffer));
            if (ret < 0) {
                printf("Error in writing to file\n");
                continue;
            }

            if (args->verbose) {
                printf("Data written to file: %s\n", filePath);
            }
        }

        isNormalDataReady = 0;
        pthread_mutex_unlock(&normalDataMutex);
    }

    free(tokenAddress);
    free(tokens);
    free(writingBuffer);
    free(normal_data_array);

    return NULL;
}

int main(int argc, char* argv[]) {
    // Variable declarations
    program_args_t args;

    ioctl_c2h_peek_data_t c2h_peek_data;

    int current_seed = 0;
    int data_len;
    int mock_datalen = 0;
    int mock_signal = 0;
    int ret;
    int total_data_len = 0;

    clock_t start, end;
    double elasped;

    unsigned char *buffer = malloc(MAX_DATA_SIZE);
	
    char qdmaDevPath[256];

    // Parse command-line arguments
    parseArguments(argc, argv, &args);

	if(args.helpBool) {
		return 0;
	}

    // Convert device and queue IDs to numeric values
    device_id_num = strtoul(args.device_id, NULL, 16);
    unsigned int queue_id_num = strtoul(args.queue_id, NULL, 10);

    // Signal handling
    signal(SIGINT, gracefulExit);
    signal(SIGTERM, gracefulExit);

    pthread_t normalDataProcessingThread;
    pthread_create(&normalDataProcessingThread, NULL, processNormalData, &args);

    if (args.mockBool) {
        if (args.verbose) {
            printf("Opening mock data file\n");
            printf("Skipping QDMA initialization\n");
        }

        // Open mock data file
        mock_fd = open("./mock/normal.txt", O_RDWR | O_NONBLOCK);
        if (mock_fd < 0) {
            perror("Error opening mock data file");
            return -1;
        }
        mock_datalen = lseek(mock_fd, 0, SEEK_END);
        lseek(mock_fd, 0, SEEK_SET);
    } else {
        // Initialize QDMA queue
        if (args.verbose) {
            printf("Initializing queue with device ID = %d, queue ID = %d\n", device_id_num, queue_id_num);
        }
        ret = queue_init(device_id_num, queue_id_num);
        // if (ret < 0) {
        //     printf("Error in initializing queue with ret = %d\n", ret);
        //     return ret;
        // }

        // Open QDMA device
        // qdmaDevPath is concatenatation of "/dev/qdma" and device_id and "-ST-" and queue_id
        snprintf(qdmaDevPath, sizeof(qdmaDevPath), "/dev/qdma%s-ST-%s", args.device_id, args.queue_id);
        if(args.verbose) {
            printf("Opening QDMA device: %s\n", qdmaDevPath);
        }
        fd = open(qdmaDevPath, O_RDWR | O_NONBLOCK);
        if (fd < 0) {
            perror("Error opening QDMA device");
            return -1;
        }

        ret = read_register(device_id_num, 0x0, &current_seed);
        if (ret < 0) {
            printf("Error in reading FPGA seed with ret = %d\n", ret);
            gracefulExit(0);
        }
        if (args.verbose) {
            printf("Current seed: %d\n", current_seed);
        }
        if(current_seed != SEED) {
            printf("Seed mismatch. Expected %d, got %d\n", SEED, current_seed);
            gracefulExit(0);
        }

        ret = write_register(device_id_num, 0x8, 0x1);
        if (ret < 0) {
            printf("Error in enabling P4 engine with ret = %d\n", ret);
            return ret;
        }
    }

    start = clock();
    // Main processing loop
    while (!shouldExit) {

        if (!args.mockBool) {
            ret = peek_qdma_data_len(fd, &c2h_peek_data);
            if (ret < 0) {
                printf("Error in peeking data length with ret = %d\n", ret);
                break;
            } else if(args.verbose) {
                printf("Data length: %d\n", c2h_peek_data.data_len);
            }
        } else {
            // wait for mock signal
            // printf("Waiting for mock signal\n");
            // scanf("%d", &mock_signal);
            // if(mock_signal != 1){
            //     break;
            // }
        }

        if (c2h_peek_data.data_len > 0 || mock_datalen > 0) {
            data_len = c2h_peek_data.data_len | mock_datalen;
            if(!args.mockBool) {
                // if(args.verbose) {
                //     printf("Reading data from QDMA device\n");
                // }
                ret = read_qdma_binary(fd, buffer+total_data_len, data_len);
                if (ret < 0) {
                    printf("Error in reading data with ret = %d\n", ret);
                    break;
                }
            } else {
                // Mock data
                // read data from file ./mock/normal.txt
                // if (args.verbose) {
                //     printf("Reading data from mock file\n");
                // }
                ret = read(mock_fd, buffer+total_data_len, data_len);
                if (ret < 0) {
                    printf("Error in reading mock data with ret = %d\n", ret);
                    break;
                }
                lseek(mock_fd, 0, SEEK_SET);
            }
            // memcpy(sharedBuffer+total_data_len, buffer+total_data_len, data_len);
            total_data_len += data_len;
        }

        end = clock();
        elasped = (double)(end - start) / CLOCKS_PER_SEC;
        // if elasped time is more than 1 second, trigger signal
        if (elasped > 1) {
            if(args.verbose) {
                printf("Elasped time: %lf\n", elasped);
                printf("Triggering signal\n");
            }
            pthread_mutex_lock(&normalDataMutex);
            memcpy(sharedBuffer, buffer, total_data_len);
            sharedBufferLength = total_data_len;
            isNormalDataReady = 1;
            pthread_cond_signal(&normalDataCond);
            pthread_mutex_unlock(&normalDataMutex);
            total_data_len = 0;
            start = clock();
        }
        
    }

    pthread_join(normalDataProcessingThread, NULL);

    free(buffer);

    if(!shouldExit) {
        gracefulExit(0);
    }

    return 0;
}
