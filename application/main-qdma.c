#include <buffer_linked_list.h>
#include "data_manager.h"
#include "db_writer.h"
#include "parse_cmd.h"
#include "qdma_fn.h"

#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h>
#include <signal.h>
#include <stdatomic.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

/*
    Constants
*/
#define BUFFER_THRESHOLD 0.85
#define MAX_WRITE_BUFFER_SIZE (1 << 30)
#define NODE_COUNT (1 << 4)
#define SEED 0xA3F7C92D

/**
 * Normal data processing
*/
#define NORMAL_MAX_BUFFER_COUNT (1 << 23)
#define NORMAL_MAX_BUFFER_SIZE (1 << 5)
#define NORMAL_MAX_DATA_SIZE (NORMAL_MAX_BUFFER_COUNT * NORMAL_MAX_BUFFER_SIZE)

/**
 * NetFlow Record processing
*/
#define NETFLOW_MAX_BUFFER_COUNT (1 << 22)
#define NETFLOW_MAX_BUFFER_SIZE 52
#define NETFLOW_MAX_DATA_SIZE (NETFLOW_MAX_BUFFER_COUNT * NETFLOW_MAX_BUFFER_SIZE)

/*
    Shared Variables
*/

volatile int shouldExit = 0;
volatile int normalReady = 0;
volatile int netflowReady = 0;
CircularBuffer normalQueue;
CircularBuffer netflowQueue;

int normal_fd, normal_mock_fd;
int netflow_fd, netflow_mock_fd;
unsigned int device_id_num;

time_t time_now;
struct tm *tm_now;

void gracefulExit(int sig) {
    printf("Caught signal %d\n", sig);
    shouldExit = 1;
}

/** getCurrentTimestamp
 * - Gets the current timestamp in the format: YYYYMMDD_HHMMSS
*/
void getCurrentTimestamp(char* timestamp, int size) {
    time(&time_now);
    tm_now = localtime(&time_now);
    strftime(timestamp, size, "%Y%m%d_%H%M%S", tm_now);
}

/**
 * ensureDirectoryExists
 * - Ensures that the directory at the given path exists
 * - If the directory does not exist, creates the directory
*/
void ensureDirectoryExists(const char* path) {
    if(mkdir(path, 0777) < 0) {
        if(errno != EEXIST) {
            printf("Failed to create directory: %s\n", path);
            gracefulExit(0);
        }
    }
}

/** ----------------------------------------------------------------------------------------------------
 * Normal Data Threads
*/

/**
 * readNormalData
 * - Thread function to read normal data
*/
void* readNormalData(void *programArgs) {
    program_args_t* args = (program_args_t*)programArgs;

    int normal_mock_datalen = 0;
    if(args->mockBool) {
/**
 * Initialize mock data file
*/
        printf("Normal: Opening mock data file\n");

        normal_mock_fd = open("./mock/normal.txt", O_RDONLY | O_NONBLOCK);
        if(normal_mock_fd < 0) {
            printf("Normal: Failed to open mock data file\n");
            gracefulExit(0);
            goto normalReadingFilesClosing;
        }
        normal_mock_datalen = lseek(normal_mock_fd, 0, SEEK_END);
        lseek(normal_mock_fd, 0, SEEK_SET);
    }

    int datalen = 0;
    int total_datalen = 0;
    ioctl_c2h_peek_data_t c2h_peek_data;
    unsigned char *data = malloc(NORMAL_MAX_DATA_SIZE);
    _Atomic(DataNode*) producer_node;

    struct timespec start, end;
    double elapsed_time;
    clock_gettime(CLOCK_MONOTONIC, &start);

    while(!normalReady && !shouldExit) {
        usleep(1000);
    }

    if(args->verbose) {
        printf("Normal data reading thread started\n");
    }

    while(!shouldExit) {
/**
 * Get Data
*/
        if(!args->mockBool) {
            if(peek_qdma_data_len(normal_fd, &c2h_peek_data) < 0) {
                printf("Normal: Failed to peek QDMA data length\n");
                gracefulExit(0);
            }
            datalen = c2h_peek_data.data_len;
            if(datalen > 0 && read_qdma_binary(normal_fd, data, datalen) < 0) {
                printf("Normal: Failed to read QDMA data\n");
                gracefulExit(0);
            }
        } else {
            datalen = normal_mock_datalen;
            if(read(normal_mock_fd, data, datalen) < 0) {
                printf("Normal: Failed to read mock data\n");
                gracefulExit(0);
            }
        }
/**
 * Read Data into buffer
*/
        if(datalen > 0) {
            // get the producer node
            producer_node = atomic_load(&normalQueue.producer_ptr);

            if(producer_node->length + datalen >= NORMAL_MAX_DATA_SIZE) {
                printf("Normal: Buffer overflow detected. Skipping data\n");
            } else {
                memcpy(producer_node->data+producer_node->length, data, datalen);
                producer_node->length += datalen;
                total_datalen += datalen;
            }
        }

        if(total_datalen > 0) {
            clock_gettime(CLOCK_MONOTONIC, &end);
            elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
            if(elapsed_time > 3 || total_datalen >= ((double )NORMAL_MAX_DATA_SIZE) * BUFFER_THRESHOLD) {
                if(args->verbose) {
                    printf("Normal: Elapsed time: %f seconds\n", elapsed_time);
                    printf("Normal: Total data length: %d\n", total_datalen);
                }
                if(!getNextNodeToProduce(&normalQueue)) {
                    printf("Normal: Buffer full. Data might be lost\n");
                } else if(args->verbose) {
                    printf("Normal: Moved producer pointer to next node\n");
                }

                total_datalen = 0;
                clock_gettime(CLOCK_MONOTONIC, &start);
            }
        } else {
            clock_gettime(CLOCK_MONOTONIC, &start);
        }
    }

    normalReadingCleanup:

    if(args->verbose) {
        printf("Normal data reading thread exiting\n");
    }

    free(data);

    normalReadingFilesClosing:
    if(normal_fd > 0) {
        close(normal_fd);
    }

    if(normal_mock_fd > 0) {
        close(normal_mock_fd);
    }

    return NULL;
}

/**
 * processNormalData
 * - Thread function to process normal data
 * - Tokenizes the raw data
 * - Extracts normal data from the tokens
 * - Writes the normal data to a CSV file
*/
void* processNormalData(void* programArgs) {
    program_args_t* args = (program_args_t*)programArgs;
    stat_t stats;

    int ret = 0;

    char normalDirPath[256];

    char filePath[256], timestamp[32];
    char separator[] = {0x0D, 0x0A};

    char** tokens = (char**)malloc(NORMAL_MAX_BUFFER_COUNT * sizeof(char*));
    char* tokenBuffer = (char*)malloc(NORMAL_MAX_DATA_SIZE);
    char* writingBuffer = (char*)malloc(MAX_WRITE_BUFFER_SIZE);

    for(int i=0;i<NORMAL_MAX_BUFFER_COUNT;i++) {
        tokens[i] = tokenBuffer + i * NORMAL_MAX_BUFFER_SIZE;
    }

    snprintf(normalDirPath, sizeof(normalDirPath), "%s/normal", args->dir_path);
    ensureDirectoryExists(normalDirPath);

    if (!tokens || !tokenBuffer || !writingBuffer) {
        printf("Normal: Failed to allocate memory for tokens, tokenBuffer and/or writingBuffer\n");
        gracefulExit(0);
        goto normalProcessingCleanup;
    }

    while(!normalReady && !shouldExit) {
        usleep(1000);
    }

    if(args->verbose) {
        printf("Normal data processing thread started\n");
    }

    DataNode* consumer_node;
    int numTokens = 0;
    int recordCount = 0;
    int offset = 0;
    while(!shouldExit) {
        if(getNextNodeToConsume(&normalQueue)) {
            // shouldExit = 1;

            consumer_node = atomic_load(&normalQueue.consumer_ptr);

            if(consumer_node->length > 0) {
                if(args->verbose) {
                    printf("Normal: Processing %d bytes of data\n", consumer_node->length);
                }

                numTokens = 0;
                if(tokenizeData(consumer_node->data, consumer_node->length, separator, tokens, &numTokens) < 0) {
                    printf("Normal: Failed to tokenize data\n");
                    goto write_completed;
                } else if(args->verbose) {
                    printf("Normal: Tokenized %d records\n", numTokens);
                }

                recordCount = 0;
                offset = 0;
                memset(&stats, 0, sizeof(stats));
                writeNormalDataCSVHeaders(writingBuffer, &offset);
                for(int i=0;i<numTokens;i++) {
                    extractNormalDataToCSV(writingBuffer, &offset, tokens[i], strlen(tokens[i]), &stats);
                    if(ret < 0) {
                        printf("Normal: Failed to extract normal data and write to CSV format\n");
                        continue;
                    } else if(args->verbose) {
                        if(offset > MAX_WRITE_BUFFER_SIZE * BUFFER_THRESHOLD) {
                            printf("Normal: The writing buffer is nearly full with %d bytes\n", offset);
                        }
                    }
                    recordCount++;
                }

                if(recordCount > 0) {
                    if(args->verbose) {
                        printf("Normal: Extracted %d records\n", recordCount);
                    }

                    getCurrentTimestamp(timestamp, sizeof(timestamp));
                    snprintf(filePath, sizeof(filePath), "%s/data_%s.csv", normalDirPath, timestamp);

                    if(writeToFile(filePath, writingBuffer, offset, &stats) < 0) {
                        printf("Normal: Failed to write normal data to file\n");
                        goto write_completed;
                    } else if(args->verbose) {
                        printf("Normal: Wrote %d bytes to file: %s\n", offset, filePath);
                    }
                }
            }
            write_completed:
            consumer_node->length = 0;
        } else {
            usleep(1000);
        }
    }

    normalProcessingCleanup:

    if(args->verbose) {
        printf("Normal data processing thread exiting\n");
    }

    free(tokens);
    free(tokenBuffer);
    free(writingBuffer);

    return NULL;
}

/** ----------------------------------------------------------------------------------------------------
 * NetFlow Data Threads
*/
/**
 * readNetFlowData
 * - Thread function to read NetFlow data
*/
void* readNetFlowData(void *programArgs) {
    program_args_t* args = (program_args_t*)programArgs;

    int netflow_mock_datalen = 0;
    if(args->mockBool) {
/**
 * Initialize mock data file
*/
        printf("NetFlow: Opening mock data file\n");
        printf("NetFlow: Skipping QDMA initialization\n");

        netflow_mock_fd = open("./mock/netflow.txt", O_RDONLY | O_NONBLOCK);
        if(netflow_mock_fd < 0) {
            printf("NetFlow: Failed to open mock data file\n");
            gracefulExit(0);
            goto netflowReadingFilesClosing;
        }
        netflow_mock_datalen = lseek(netflow_mock_fd, 0, SEEK_END);
        lseek(netflow_mock_fd, 0, SEEK_SET);
    }

    int datalen = 0;
    int total_datalen = 0;
    ioctl_c2h_peek_data_t c2h_peek_data;
    unsigned char *data = malloc(NETFLOW_MAX_DATA_SIZE);
    _Atomic(DataNode*) producer_node;

    struct timespec start, end;
    double elapsed_time;
    clock_gettime(CLOCK_MONOTONIC, &start);

    while(!netflowReady && !shouldExit) {
        usleep(1000);
    }

    if(args->verbose) {
        printf("NetFlow data reading thread started\n");
    }

    while(!shouldExit) {
/**
 * Get Data
*/
        if(!args->mockBool) {
            if(peek_qdma_data_len(netflow_fd, &c2h_peek_data) < 0) {
                printf("NetFlow: Failed to peek QDMA data length\n");
                gracefulExit(0);
            }
            datalen = c2h_peek_data.data_len;
            if(datalen > 0 && read_qdma_binary(netflow_fd, data, datalen) < 0) {
                printf("NetFlow: Failed to read QDMA data\n");
                gracefulExit(0);
            }
        } else {
            datalen = netflow_mock_datalen;
            if(read(netflow_mock_fd, data, datalen) < 0) {
                printf("NetFlow: Failed to read mock data\n");
                gracefulExit(0);
            }
        }
/**
 * Read Data into buffer
*/
        if(datalen > 0) {
            // get the producer node
            producer_node = atomic_load(&netflowQueue.producer_ptr);

            if(producer_node->length + datalen >= NETFLOW_MAX_DATA_SIZE) {
                printf("NetFlow: Buffer overflow detected. Skipping data\n");
            } else {
                memcpy(producer_node->data+producer_node->length, data, datalen);
                producer_node->length += datalen;
                total_datalen += datalen;
            }
        }

        if(total_datalen > 0) {
            clock_gettime(CLOCK_MONOTONIC, &end);
            elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
            if(elapsed_time > 3 || total_datalen >= ((double )NETFLOW_MAX_DATA_SIZE) * BUFFER_THRESHOLD) {
                if(args->verbose) {
                    printf("NetFlow: Elapsed time: %f seconds\n", elapsed_time);
                    printf("NetFlow: Total data length: %d\n", total_datalen);
                }
                if(!getNextNodeToProduce(&netflowQueue)) {
                    printf("NetFlow: Buffer full. Data might be lost\n");
                } else if(args->verbose) {
                    printf("NetFlow: Moved producer pointer to next node\n");
                }

                total_datalen = 0;
                clock_gettime(CLOCK_MONOTONIC, &start);
            }
        } else {
            clock_gettime(CLOCK_MONOTONIC, &start);
        }
    }

    netflowReadingCleanup:

    if(args->verbose) {
        printf("NetFlow data reading thread exiting\n");
    }

    free(data);

    netflowReadingFilesClosing:
    if(netflow_fd > 0) {
        close(netflow_fd);
    }

    if(netflow_mock_fd > 0) {
        close(netflow_mock_fd);
    }

    return NULL;
}

/**
 * processNetflowData
 * - Thread function to process NetFlow data
 * - Tokenizes the raw data
 * - Extracts NetFlow data from the tokens
 * - Writes the NetFlow data to a CSV file
*/
void* processNetflowData(void* programArgs) {
    program_args_t* args = (program_args_t*)programArgs;
    stat_t stats;

    int ret = 0;

    char netflowDirPath[256];

    char filePath[256], timestamp[32];
    char separator[] = {0x0D, 0x0A};

    char** tokens = (char**)malloc(NETFLOW_MAX_BUFFER_COUNT * sizeof(char*));
    char* tokenBuffer = (char*)malloc(NETFLOW_MAX_DATA_SIZE);
    char* writingBuffer = (char*)malloc(MAX_WRITE_BUFFER_SIZE);

    for(int i=0;i<NETFLOW_MAX_BUFFER_COUNT;i++) {
        tokens[i] = tokenBuffer + i * NETFLOW_MAX_BUFFER_SIZE;
    }

    snprintf(netflowDirPath, sizeof(netflowDirPath), "%s/netflow", args->dir_path);
    ensureDirectoryExists(netflowDirPath);

    if (!tokens || !tokenBuffer || !writingBuffer) {
        printf("NetFlow: Failed to allocate memory for tokens, tokenBuffer and/or writingBuffer\n");
        gracefulExit(0);
        goto netflowProcessingCleanup;
    }

    while(!netflowReady && !shouldExit) {
        usleep(1000);
    }

    if(args->verbose) {
        printf("NetFlow data processing thread started\n");
    }

    DataNode* consumer_node;
    int numTokens = 0;
    int recordCount = 0;
    int offset = 0;
    while(!shouldExit) {
        if(getNextNodeToConsume(&netflowQueue)) {
            // shouldExit = 1;

            consumer_node = atomic_load(&netflowQueue.consumer_ptr);

            if(consumer_node->length > 0) {
                if(args->verbose) {
                    printf("NetFlow: Processing %d bytes of data\n", consumer_node->length);
                }

                numTokens = 0;
                if(tokenizeData(consumer_node->data, consumer_node->length, separator, tokens, &numTokens) < 0) {
                    printf("NetFlow: Failed to tokenize data\n");
                    goto write_completed;
                } else if(args->verbose) {
                    printf("NetFlow: Tokenized %d records\n", numTokens);
                }

                recordCount = 0;
                offset = 0;
                memset(&stats, 0, sizeof(stats));
                writeNetFlowRecordCSVHeaders(writingBuffer, &offset);
                for(int i=0;i<numTokens;i++) {
                    extractNetFlowRecordToCSV(writingBuffer, &offset, tokens[i], strlen(tokens[i]), &stats);
                    if(ret < 0) {
                        printf("NetFlow: Failed to extract NetFlow data and write to CSV format\n");
                        continue;
                    } else if(args->verbose) {
                        if(offset > MAX_WRITE_BUFFER_SIZE * BUFFER_THRESHOLD) {
                            printf("NetFlow: The writing buffer is nearly full with %d bytes\n", offset);
                        }
                    }
                    recordCount++;
                }

                if(recordCount > 0) {
                    if(args->verbose) {
                        printf("NetFlow: Extracted %d records\n", recordCount);
                    }

                    getCurrentTimestamp(timestamp, sizeof(timestamp));
                    snprintf(filePath, sizeof(filePath), "%s/data_%s.csv", netflowDirPath, timestamp);

                    if(writeToFile(filePath, writingBuffer, offset, &stats) < 0) {
                        printf("NetFlow: Failed to write NetFlow data to file\n");
                        goto write_completed;
                    } else if(args->verbose) {
                        printf("NetFlow: Wrote %d bytes to file: %s\n", offset, filePath);
                    }
                }
            }
            write_completed:
            consumer_node->length = 0;
        } else {
            usleep(1000);
        }
    }

    netflowProcessingCleanup:

    if(args->verbose) {
        printf("NetFlow data processing thread exiting\n");
    }

    free(tokens);
    free(tokenBuffer);
    free(writingBuffer);

    return NULL;
}

/**
 * main
 * - Main function to initialize the program
 * - Parses command line arguments
 * - Initializes QDMA and Circular Queue
 * - Starts the normal data reading and processing threads
 * - Starts the NetFlow data reading and processing threads
*/
int main(int argc, char* argv[]) {
    program_args_t args;
    parseArguments(argc, argv, &args);

    if(args.helpBool) {
        return 0;
    }

/**
 * Initialize DB Writer
*/
    initDBWriter("localhost", 8086, "file_records");

    device_id_num = strtoul(args.device_id, NULL, 16);
    unsigned int queue_id_num = strtoul(args.queue_id, NULL, 10);

/**
 * Initialize Normal Data Threads and Circular Queue
*/
    pthread_t normal_reading_thread;
    pthread_t normal_processing_thread;
    if(args.data & NORMAL_DATA_CMD) {
        initializeCircularQueue(&normalQueue, NODE_COUNT, NORMAL_MAX_DATA_SIZE);

        pthread_create(&normal_reading_thread, NULL, readNormalData, &args);
        pthread_create(&normal_processing_thread, NULL, processNormalData, &args);
    }

/**
 * Initialize NetFlow Data Threads and Circular Queue
*/
    pthread_t netflow_reading_thread;
    pthread_t netflow_processing_thread;
    if(args.data & NETFLOW_DATA_CMD) {
        initializeCircularQueue(&netflowQueue, NODE_COUNT, NETFLOW_MAX_DATA_SIZE);

        pthread_create(&netflow_reading_thread, NULL, readNetFlowData, &args);
        pthread_create(&netflow_processing_thread, NULL, processNetflowData, &args);
    }

    signal(SIGINT, gracefulExit);
    signal(SIGTERM, gracefulExit);
    // signal(SIGSEGV, gracefulExit);

    if (!args.mockBool) {
/**
 * Initialize QDMA for normal Data
*/
        if (args.verbose) {
            printf("Initializing QDMA for normal data with device_id: %s, queue_id: %d\n", args.device_id, queue_id_num);
        }
        if(queue_init(device_id_num, queue_id_num) < 0) {
            // printf("Failed to initialize QDMA\n");
            // return -1;
        }

        char qdmaNormalDevPath[64];
        snprintf(qdmaNormalDevPath, sizeof(qdmaNormalDevPath), "/dev/qdma%s-ST-%d", args.device_id, queue_id_num);
        
        if(args.verbose) {
            printf("Opening QDMA device: %s\n", qdmaNormalDevPath);
        }
        normal_fd = open(qdmaNormalDevPath, O_RDWR | O_NONBLOCK);
        if(normal_fd < 0) {
            printf("Failed to open QDMA device\n");
            gracefulExit(0);
            goto mainCleanup;
        }

/**
 * Initialize QDMA for NetFlow Data
*/
        if (args.verbose) {
            printf("Initializing QDMA for NetFlow data with device_id: %s, queue_id: %d\n", args.device_id, queue_id_num+1);
        }
        if(queue_init(device_id_num, queue_id_num+1) < 0) {
            // printf("Failed to initialize QDMA\n");
            // return -1;
        }

        char qdmaNetflowDevPath[64];
        snprintf(qdmaNetflowDevPath, sizeof(qdmaNetflowDevPath), "/dev/qdma%s-ST-%d", args.device_id, queue_id_num+1);
        
        if(args.verbose) {
            printf("Opening QDMA device: %s\n", qdmaNetflowDevPath);
        }
        normal_fd = open(qdmaNetflowDevPath, O_RDWR | O_NONBLOCK);
        if(normal_fd < 0) {
            printf("Failed to open QDMA device\n");
            gracefulExit(0);
            goto mainCleanup;
        }

/**
 * Check FPGA seed
*/
        unsigned int current_seed;
        if(read_register(device_id_num, 0x0, &current_seed) < 0) {
            printf("Failed to read seed\n");
            gracefulExit(0);
            goto mainCleanup;
        }
        if(args.verbose) {
            printf("Current seed: %x\n", current_seed);
        }
        if(current_seed != SEED) {
            printf("Seed mismatch. Expected: %x, Got: %x\n", SEED, current_seed);
            gracefulExit(0);
            goto mainCleanup;
        }

        if(write_register(device_id_num, 0x8, 0x1) < 0) {
            printf("Failed to enabling P4 engine");
            gracefulExit(0);
            goto mainCleanup;
        }
    }

    normalReady = 1;
    netflowReady = 1;

    while(!shouldExit) {
        usleep(10000);
    }

    if(args.verbose) {
        printf("Cleaning up main thread\n");
    }

    if(args.data & NORMAL_DATA_CMD) {
        pthread_join(normal_processing_thread, NULL);
        pthread_join(normal_reading_thread, NULL);

        destroyCircularQueue(&normalQueue);
    }

    if(args.data & NETFLOW_DATA_CMD) {
        pthread_join(netflow_processing_thread, NULL);
        pthread_join(netflow_reading_thread, NULL);

        destroyCircularQueue(&netflowQueue);
    }

    destroyDBWriter();

    mainCleanup:

    if(!args.mockBool && write_register(device_id_num, 0x8, 0x0) < 0) {
        printf("Failed to disable P4 engine");
    }

    if(args.verbose) {
        printf("Exiting main thread\n");
    }

    return 0;
}