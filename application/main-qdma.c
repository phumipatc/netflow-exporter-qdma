#include "parse_cmd.h"
#include "data_manager.h"
#include "db_writer.h"
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
#define BUFFER_THRESHOLD 0.9
#define MAX_RECORDS (1 << 23)
#define MAX_RECORDS_SIZE (1 << 5)
#define MAX_DATA_SIZE (MAX_RECORDS * MAX_RECORDS_SIZE)
#define MAX_WRITE_SIZE (1 << 30)
#define NODE_COUNT (1 << 5)
#define SEED 0xA3F7C92D

/*
    Data structures
*/
// circular linked list node
typedef struct DataNode {
    char data[MAX_DATA_SIZE];
    int length;
    _Atomic(struct DataNode*) next;
} DataNode;

// Circular buffer structure
typedef struct {
    _Atomic(DataNode*) producer_ptr;
    _Atomic(DataNode*) consumer_ptr;

} CircularBuffer;

volatile int shouldExit = 0;
CircularBuffer queue;

int fd, mock_fd;
unsigned int device_id_num;

time_t time_now;
struct tm *tm_now;

void gracefulExit(int sig) {
    printf("Caught signal %d\n", sig);
    shouldExit = 1;
}

/**
 * initializeCircularQueue
 * - Initializes the circular buffer with NODE_COUNT number of nodes
 * - Need to be called before spawning any threads
*/
void initializeCircularQueue() {
    DataNode* head = NULL;
    DataNode* prev = NULL;

    for(int i=0;i<NODE_COUNT;i++) {
        DataNode* node = (DataNode*)malloc(sizeof(DataNode));
        memset(node->data, 0, MAX_DATA_SIZE);
        node->length = 0;
        node->next = NULL;

        if (!head) {
            head = node;
        } else {
            prev->next = node;
        }
        prev = node;
    }
    prev->next = head;

    queue.producer_ptr = head->next;
    queue.consumer_ptr = head;

}

/**
 * destroyCircularQueue
 * - Frees the memory allocated for the circular buffer
 * - Need to be called after all threads have exited
*/
void destroyCircularQueue() {
    DataNode* head = queue.producer_ptr;
    DataNode* current = head;
    DataNode* next = head->next;

    while(next != head) {
        free(current);
        current = next;
        next = next->next;
    }

    free(current);
}

/**
 * moveProducerPtr
 * - Moves the producer pointer to the next node in the circular buffer
 * - Requires atomic operations to ensure thread safety
*/
void moveProducerPtr() {
    atomic_store(&queue.producer_ptr, atomic_load(&queue.producer_ptr)->next);
}

/**
 * moveConsumerPtr
 * - Moves the consumer pointer to the next node in the circular buffer
 * - Requires atomic operations to ensure thread safety
*/
void moveConsumerPtr() {
    atomic_store(&queue.consumer_ptr, atomic_load(&queue.consumer_ptr)->next);
}

/**
 * getNextNodeToConsume
 * - If the consumer has not caught up with the producer, moves the consumer pointer to the next node in the circular buffer
 * Returns:
 * - 0 if the consumer has caught up with the producer
 * - 1 if the consumer has not caught up with the producer, and the consumer pointer has been moved
*/
int getNextNodeToConsume() {
    // check if consumer has caught up with producer
    if(atomic_load(&queue.consumer_ptr)->next == atomic_load(&queue.producer_ptr)) {
        return 0;
    }

    moveConsumerPtr();

    return 1;
}

/**
 * getNextNodeToProduce
 * - If the producer has not caught up with the consumer, moves the producer pointer to the next node in the circular buffer
 * Returns:
 * - 0 if the next node is the same as the consumer node
 * - 1 if the next node is different from the consumer node, and the producer pointer has been moved
*/
int getNextNodeToProduce() {
    // check if producer has caught up with consumer
    if(atomic_load(&queue.producer_ptr)->next == atomic_load(&queue.consumer_ptr)) {
        return 0;
    }

    moveProducerPtr();

    return 1;
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

/**
 * processNormalData
 * - Thread function to process normal data
 * - Tokenizes the raw data
 * - Extracts normal data from the tokens
 * - Writes the normal data to a CSV file
*/
void* processNormalData(void* programArgs) {
    program_args_t* args = (program_args_t*)programArgs;

    int ret = 0;

    char normalDirPath[256];

    char filePath[256], timestamp[32];
    char separator[] = {0x0D, 0x0A};

    char** tokens = (char**)malloc(MAX_RECORDS * sizeof(char*));
    char* tokenBuffer = (char*)malloc(MAX_DATA_SIZE);
    char* writingBuffer = (char*)malloc(MAX_WRITE_SIZE);

    for(int i=0;i<MAX_RECORDS;i++) {
        tokens[i] = tokenBuffer + i * MAX_RECORDS_SIZE;
    }

    snprintf(normalDirPath, sizeof(normalDirPath), "%s/normal", args->dir_path);
    ensureDirectoryExists(normalDirPath);

    if (!tokens || !tokenBuffer || !writingBuffer) {
        printf("Failed to allocate memory for tokens, tokenBuffer and/or writingBuffer\n");
        gracefulExit(0);
        goto normalProcessingCleanup;
    }

    if(args->verbose) {
        printf("Normal data processing thread started\n");
    }

    DataNode* consumer_node;
    int numTokens = 0;
    int recordCount = 0;
    int offset = 0;
    while(!shouldExit) {
        if(getNextNodeToConsume()) {
            // shouldExit = 1;

            consumer_node = atomic_load(&queue.consumer_ptr);

            if(consumer_node->length > 0) {
                if(args->verbose) {
                    printf("Processing %d bytes of data\n", consumer_node->length);
                }

                numTokens = 0;
                if(tokenizeData(consumer_node->data, consumer_node->length, separator, tokens, &numTokens) < 0) {
                    printf("Failed to tokenize data\n");
                    goto write_completed;
                } else if(args->verbose) {
                    printf("Tokenized %d records\n", numTokens);
                }

                recordCount = 0;
                offset = 0;
                writeNormalDataCSVHeaders(writingBuffer, &offset);
                for(int i=0;i<numTokens;i++) {
                    extractNormalDataToCSV(writingBuffer, &offset, tokens[i], strlen(tokens[i]));
                    if(ret < 0) {
                        printf("Failed to extract normal data and write to CSV format\n");
                        continue;
                    } else if(args->verbose) {
                        if(offset > MAX_WRITE_SIZE * BUFFER_THRESHOLD) {
                            printf("The writing buffer is nearly full with %d bytes\n", offset);
                        }
                    }
                    recordCount++;
                }

                if(recordCount > 0) {
                    if(args->verbose) {
                        printf("Extracted %d records\n", recordCount);
                    }

                    getCurrentTimestamp(timestamp, sizeof(timestamp));
                    snprintf(filePath, sizeof(filePath), "%s/data_%s.csv", normalDirPath, timestamp);

                    if(writeToFile(filePath, writingBuffer, offset) < 0) {
                        printf("Failed to write normal data to file\n");
                        goto write_completed;
                    } else if(args->verbose) {
                        printf("Wrote %d bytes to file: %s\n", offset, filePath);
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

int main(int argc, char* argv[]) {
    program_args_t args;
    parseArguments(argc, argv, &args);

    if(args.helpBool) {
        return 0;
    }

    device_id_num = strtoul(args.device_id, NULL, 16);
    unsigned int queue_id_num = strtoul(args.queue_id, NULL, 10);
    int mock_datalen = 0;

    if(args.mockBool) {
/**
 * Initialize mock data file
*/
        printf("Opening mock data file\n");
        printf("Skipping QDMA initialization\n");

        mock_fd = open("./mock/normal.txt", O_RDONLY | O_NONBLOCK);
        if(mock_fd < 0) {
            printf("Failed to open mock data file\n");
            return -1;
        }
        mock_datalen = lseek(mock_fd, 0, SEEK_END);
        lseek(mock_fd, 0, SEEK_SET);
    } else {
/**
 * Initialize QDMA
*/
        if (args.verbose) {
            printf("Initializing QDMA with device_id: %s, queue_id: %s\n", args.device_id, args.queue_id);
        }
        if(queue_init(device_id_num, queue_id_num) < 0) {
            // printf("Failed to initialize QDMA\n");
            // return -1;
        }

        char qdmaDevPath[64];
        snprintf(qdmaDevPath, sizeof(qdmaDevPath), "/dev/qdma%s-ST-%s", args.device_id, args.queue_id);
        
        if(args.verbose) {
            printf("Opening QDMA device: %s\n", qdmaDevPath);
        }
        fd = open(qdmaDevPath, O_RDWR | O_NONBLOCK);
        if(fd < 0) {
            printf("Failed to open QDMA device\n");
            return -1;
        }

        unsigned int current_seed;
        if(read_register(device_id_num, 0x0, &current_seed) < 0) {
            printf("Failed to read seed\n");
            return -1;
        }
        if(args.verbose) {
            printf("Current seed: %x\n", current_seed);
        }
        if(current_seed != SEED) {
            printf("Seed mismatch. Expected: %x, Got: %x\n", SEED, current_seed);
            gracefulExit(0);
            goto cleanup;
        }

        if(write_register(device_id_num, 0x8, 0x1) < 0) {
            printf("Failed to enabling P4 engine");
            gracefulExit(0);
            goto cleanup;
        }
    }

/**
 * Initialize Circular Queue
*/
    initializeCircularQueue();

/**
 * Initialize Processing Thread
*/
    pthread_t processing_thread;
    pthread_create(&processing_thread, NULL, processNormalData, &args);

    signal(SIGINT, gracefulExit);
    signal(SIGTERM, gracefulExit);
    // signal(SIGSEGV, gracefulExit);

    int datalen = 0;
    int total_datalen = 0;
    ioctl_c2h_peek_data_t c2h_peek_data;
    unsigned char *data = malloc(MAX_DATA_SIZE);
    _Atomic(DataNode*) producer_node;

    struct timespec start, end;
    double elapsed_time;
    clock_gettime(CLOCK_MONOTONIC, &start);
    while(!shouldExit) {
/**
 * Get Data
*/
        if(!args.mockBool) {
            if(peek_qdma_data_len(fd, &c2h_peek_data) < 0) {
                printf("Failed to peek QDMA data length\n");
                gracefulExit(0);
            }
            datalen = c2h_peek_data.data_len;
            if(datalen > 0 && read_qdma_binary(fd, data, datalen) < 0) {
                printf("Failed to read QDMA data\n");
                gracefulExit(0);
            }
        } else {
            datalen = mock_datalen;
            if(read(mock_fd, data, datalen) < 0) {
                printf("Failed to read mock data\n");
                gracefulExit(0);
            }
        }
/**
 * Read Data into buffer
*/
        if(datalen > 0) {
            // get the producer node
            producer_node = atomic_load(&queue.producer_ptr);

            if(producer_node->length + datalen >= MAX_DATA_SIZE) {
                printf("Buffer overflow detected. Skipping data\n");
            } else {
                memcpy(producer_node->data+producer_node->length, data, datalen);
                producer_node->length += datalen;
                total_datalen += datalen;
            }
        }

        if(total_datalen > 0) {
            clock_gettime(CLOCK_MONOTONIC, &end);
            elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
            if(elapsed_time > 3 || total_datalen >= ((double )MAX_DATA_SIZE) * BUFFER_THRESHOLD) {
                if(args.verbose) {
                    printf("Elapsed time: %f seconds\n", elapsed_time);
                    printf("Total data length: %d\n", total_datalen);
                }
                if(!getNextNodeToProduce()) {
                    printf("Buffer full. Data might be lost\n");
                } else if(args.verbose) {
                    printf("Moved producer pointer to next node\n");
                }

                total_datalen = 0;
                clock_gettime(CLOCK_MONOTONIC, &start);
            }
        } else {
            clock_gettime(CLOCK_MONOTONIC, &start);
        }
    }

    if(args.verbose) {
        printf("Cleaning up main thread\n");
    }

    pthread_join(processing_thread, NULL);

    destroyCircularQueue();

    free(data);

    cleanup:

    if(!args.mockBool && write_register(device_id_num, 0x8, 0x0) < 0) {
        printf("Failed to disable P4 engine");
    }

    if(fd > 0) {
        close(fd);
    }

    if(mock_fd > 0) {
        close(mock_fd);
    }

    if(args.verbose) {
        printf("Exiting main thread\n");
    }

    return 0;
}