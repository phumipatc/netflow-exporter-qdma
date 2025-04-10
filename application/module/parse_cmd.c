#include "parse_cmd.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printUsage(const char* programName) {
    printf("Usage: %s [OPTIONS]\n", programName);
    printf("Options:\n");
    printf("  -v                Enable verbose mode\n");
    printf("  -did <device>     Specify device ID (default: 1000)\n");
    printf("  -qid <queue>      Specify queue ID (default: 32)\n");
    printf("  -dirpath <path>   Specify directory path for output (default: /media/hoshino/nvme/netflow/)\n");
    printf("  -h                Show this help message\n");
    printf("  -mock             Enable mock mode\n");
    exit(0);
}

void parseArguments(int argc, char* argv[], program_args_t* args) {
    // Set default values
    args->verbose = 0;
    args->helpBool = 0;
    args->mockBool = 0;
    args->data = 0;
    strncpy(args->device_id, "01000", sizeof(args->device_id));
    strncpy(args->queue_id, "32", sizeof(args->queue_id));
    strncpy(args->dir_path, "/media/hoshino/nvme/netflow", sizeof(args->dir_path));

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-v") == 0) {
            args->verbose = 1;
        } else if (strcmp(argv[i], "-did") == 0 && i + 1 < argc) {
            strncpy(args->device_id, argv[++i], sizeof(args->device_id));
        } else if (strcmp(argv[i], "-qid") == 0 && i + 1 < argc) {
            strncpy(args->queue_id, argv[++i], sizeof(args->queue_id));
        } else if (strcmp(argv[i], "-dirpath") == 0 && i + 1 < argc) {
            strncpy(args->dir_path, argv[++i], sizeof(args->dir_path));
        } else if (strcmp(argv[i], "-h") == 0) {
			args->helpBool = 1;
            printUsage(argv[0]);
        } else if (strcmp(argv[i], "-mock") == 0) {
            args->mockBool = 1;
            args->verbose = 1;
        } else if (strcmp(argv[i], "-normal") == 0) {
            args->data |= NORMAL_DATA_CMD;
        } else if (strcmp(argv[i], "-netflow") == 0) {
            args->data |= NETFLOW_DATA_CMD;
        } else {
            printf("Unknown argument: %s\n", argv[i]);
			args->helpBool = 1;
            printUsage(argv[0]);
        }
    }

    if(args->data == 0) {
        args->data |= NORMAL_DATA_CMD;
        args->data |= NETFLOW_DATA_CMD;
    }

	if (args->verbose) {
		printf("Verbose mode enabled\n");
        printf("Mock mode: %s\n", args->mockBool ? "enabled" : "disabled");
        printf("Data mode: %s%s\n", 
            (args->data & NORMAL_DATA_CMD) ? "Normal " : "", 
            (args->data & NETFLOW_DATA_CMD) ? "NetFlow " : "");
		printf("Device ID: %s\n", args->device_id);
		printf("Queue ID: %s\n", args->queue_id);
		printf("Directory path: %s\n", args->dir_path);
	}
}
