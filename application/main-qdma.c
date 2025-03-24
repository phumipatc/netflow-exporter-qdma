#include "parse_cmd.h"
#include "data_manager.h"
#include "db_writer.h"
#include "qdma_fn.h"

#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int fd; // Global file descriptor for graceful exit
int mock_fd; // Global file descriptor for mock data

// Signal handler
void gracefulExit(int sig) {
    printf("Caught signal %d\n", sig);
    if (fd >= 0) {
        close(fd);
        printf("File descriptor closed.\n");
    }

    if (mock_fd >= 0) {
        close(mock_fd);
        printf("Mock file descriptor closed.\n");
    }

    printf("Exiting...\n");
    exit(0);
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

int main(int argc, char* argv[]) {
    // Variable declarations
    program_args_t args;

    ioctl_c2h_peek_data_t c2h_peek_data;
    normal_data_t normal_data_array[512];

    int data_len;
    int mock_datalen = 0;
    int mock_signal = 0;
    int numTokens;
    int recordCount;
    int ret;

    unsigned char buffer[512 * 2048]; // Buffer for multiple records

	char filePath[256];
    char qdmaDevPath[256];
	char normalDirPath[256];
    char netflowDirPath[256];
    char separator[] = {0x0D, 0x0A};
	char timestamp[32];
    char token_address[512][2048]; // Global token address for tokenizing data
    char **tokens = (char **)token_address;
	char writingBuffer[2048 * 512]; // Buffer for multiple records

    // Parse command-line arguments
    parseArguments(argc, argv, &args);

	if(args.helpBool) {
		return 0;
	}

    // Ensure directories exist
    snprintf(normalDirPath, sizeof(normalDirPath), "%s/normal", args.dir_path);
    snprintf(netflowDirPath, sizeof(netflowDirPath), "%s/full", args.dir_path);
    ensureDirectoryExists(normalDirPath);
    ensureDirectoryExists(netflowDirPath);

    // Convert device and queue IDs to numeric values
    unsigned int device_id_num = strtoul(args.device_id, NULL, 16);
    unsigned int queue_id_num = strtoul(args.queue_id, NULL, 10);

    // Signal handling
    signal(SIGINT, gracefulExit);
    signal(SIGTERM, gracefulExit);

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
        mock_datalen = lseek(mock_fd, 0, SEEK_END) + 1;
        lseek(mock_fd, 0, SEEK_SET);
    } else {
        // Initialize QDMA queue
        if (args.verbose) {
            printf("Initializing queue with device ID = %d, queue ID = %d\n", device_id_num, queue_id_num);
        }
        ret = queue_init(device_id_num, queue_id_num);
        if (ret < 0) {
            printf("Error in initializing queue with ret = %d\n", ret);
            return ret;
        }

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
    }

    // Main processing loop
    while (1) {
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
            printf("Waiting for mock signal\n");
            scanf("%d", &mock_signal);
        }

        if (c2h_peek_data.data_len > 0 || mock_datalen > 0) {
            data_len = c2h_peek_data.data_len | mock_datalen;
            if(!args.mockBool) {
                if(args.verbose) {
                    printf("Reading data from QDMA device\n");
                }
                ret = read_qdma_binary(fd, buffer, data_len);
                if (ret < 0) {
                    printf("Error in reading data with ret = %d\n", ret);
                    break;
                }
            } else {
                // Mock data
                // read data from file ./mock/normal.txt
                if (args.verbose) {
                    printf("Reading data from mock file\n");
                }
                ret = read(mock_fd, buffer, data_len);
                if (ret < 0) {
                    printf("Error in reading mock data with ret = %d\n", ret);
                    break;
                }
            }

            // the separator is array of 2 bytes, 0x0D and 0x0A
            
            ret = tokenizeData(buffer, separator, tokens, &numTokens);
            if (ret < 0) {
                printf("Error in tokenizing data with ret = %d\n", ret);
                continue;
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

                if (args.verbose) {
                    printf("Data written to file: %s\n", filePath);
                }
            }
        }
    }

    close(fd); // Close file descriptor before exit
    return 0;
}
