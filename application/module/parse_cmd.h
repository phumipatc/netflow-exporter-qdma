#ifndef PARSE_CMD_H
#define PARSE_CMD_H

#include <stddef.h>

#define NORMAL_DATA_CMD 1
#define NETFLOW_DATA_CMD 2

// Struct to hold the program arguments
typedef struct {
    int verbose;
	int helpBool;
    int mockBool;
    int data;
    char device_id[16];
    char queue_id[16];
    char dir_path[128];
} program_args_t;

// Function to parse command-line arguments
void parseArguments(int argc, char* argv[], program_args_t* args);

// Function to print usage
void printUsage(const char* programName);

#endif // PARSE_CMD_H
