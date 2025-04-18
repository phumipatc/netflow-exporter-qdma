#include<fcntl.h>
#include<sys/ioctl.h>
#include<iostream>
#include<signal.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>

using namespace std;

struct args_t {
	int mode;
	int size;
	char outputFile[256];
	char qid[8];
};

// Define the same structure used in the kernel
struct ioctl_c2h_peek_data_t {
    unsigned int udd_cnt;
    unsigned int pkt_cnt;
    unsigned int data_len;
};
ioctl_c2h_peek_data_t c2h_peek_data = {0, 0, 0};

// Define the IOCTL command values (ensure they match kernel module)
#define QDMA_CDEV_IOCTL_C2H_PEEK 1
#define THRESHOLD 0.95

void peek(int fd) {
	// Call the QDMA_CDEV_IOCTL_C2H_PEEK IOCTL command
	if (ioctl(fd, QDMA_CDEV_IOCTL_C2H_PEEK, &c2h_peek_data) != 0) {
		perror("ioctl failed");
		close(fd);
		exit(errno);
	}
}

int shouldExit = 0;

void signalHandler(int signum) {
	shouldExit = 1;
}

void printUsage(const char* programName) {
	printf("Usage: %s -m <mode> -s <size> -o <outputFile>\n", programName);
	printf("Options:\n");
	printf("  -m <mode>         : Mode of operation (e.g., 0 for single read, 1 for continuous)\n");
	printf("  -s <size>        : Size of the buffer to read/write\n");
	printf("  -o <outputFile>  : Output file path for continuous mode (default is 'output.bin')\n");
	printf("  -q <qid>         : QDMA ID (default is 32)\n");
}

int main(int argc, char* argv[]){
	// read size of the buffer
	args_t args;

	args.mode = 0; // Default mode
	args.size = 0; // Default size
	args.outputFile[0] = '\0'; // Default output file
	args.qid[0] = '\0'; // Default QDMA ID

	for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-m") == 0 && i + 1 < argc) {
            args.mode = atoi(argv[++i]);
			printf("mode: %d\n", args.mode);
        } else if (strcmp(argv[i], "-s") == 0 && i + 1 < argc) {
            args.size = atoi(argv[++i]);
			printf("size: %d\n", args.size);
		} else if (strcmp(argv[i], "-o") == 0 && i + 1 < argc) {
			strncpy(args.outputFile, argv[++i], sizeof(args.outputFile) - 1);
			args.outputFile[sizeof(args.outputFile) - 1] = '\0'; // Ensure null-termination
			printf("outputFile: %s\n", args.outputFile);
		} else if (strcmp(argv[i], "-q") == 0 && i + 1 < argc) {
			strncpy(args.qid, argv[++i], sizeof(args.qid) - 1);
			args.qid[sizeof(args.qid) - 1] = '\0'; // Ensure null-termination
			printf("qid: %s\n", args.qid);
        } else {
            printf("Unknown argument: %s\n", argv[i]);
            printUsage(argv[0]);
			return 1;
        }
    }

	if(args.qid[0] == '\0') {
		printf("Warning: QDMA ID is not set, using default ID of 32\n");
		strncpy(args.qid, "32", sizeof(args.qid) - 1);
	}

	if(args.mode == 0 && args.size == 0) {
		printf("Error: Size of the buffer is not set\n");
		printUsage(argv[0]);
		return 1;
	} else if(args.mode == 1) {
		if(args.size == 0) {
			// at least 128MB for continuous mode
			printf("Warning: Size of the buffer is not set, using default size of 1MB\n");
			args.size = 1024*1024; // 1MB
		}
		if(args.outputFile[0] == '\0') {
			printf("Warning: Output file is not set, using default output file 'output.bin'\n");
			strncpy(args.outputFile, "output.bin", sizeof(args.outputFile) - 1);
		}
	}

	char devicePath[256];
	snprintf(devicePath, sizeof(devicePath), "/dev/qdma01000-ST-%s", args.qid);
	printf("Device path: %s\n", devicePath);

	unsigned char buffer[args.size];
	int fd = open(devicePath, O_RDWR | O_NONBLOCK);
	if (fd < 0) {
		perror("Failed to open the device");
		return errno;
	}
	int readSize = 0;
	if (args.mode == 0) {
		printf("Single read mode selected\n");
		peek(fd);

		if (c2h_peek_data.data_len == 0) {
			printf("No data available to read\n");
			return 0;
		}

		int res = read(fd, buffer, args.size);

		if(res < 0) {
			perror("Failed to read the device");
			return errno;
		}

		printf("read size: %d\n",res);
		for(int i=0;i<res;i++){
			printf("%02X ", buffer[i]);
		}
	} else {
		printf("Continuous mode selected\n");
		signal(SIGINT, signalHandler);
		signal(SIGTERM, signalHandler);

		while(!shouldExit) {
			peek(fd);
			if (c2h_peek_data.data_len > 0) {
				int res = read(fd, buffer + readSize, c2h_peek_data.data_len);
				if(res < 0) {
					perror("Failed to read the device");
					break;
				}
				readSize += res;
				if(readSize >= args.size * THRESHOLD) {
					printf("Buffer is nearly full, %d bytes read\n", readSize);
					break;
				}
				
			} else {
				usleep(1000); // Sleep for 1ms
			}
		}

		if (readSize > 0) {
			FILE* outputFile = fopen(args.outputFile, "wb");
			if (outputFile) {
				fwrite(buffer, 1, readSize, outputFile);
				fclose(outputFile);
				printf("Data written to %s\n", args.outputFile);
			} else {
				perror("Failed to open output file");
			}
		} else {
			printf("No data read from the device\n");
		}
	}
	return 0;
}
