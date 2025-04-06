#include "data_manager.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// convert value to char array stored in buffer and return the number of characters written
int toString(unsigned int value, char *buffer, char *optional) {
	return sprintf(buffer, "%u%s", value, optional);
}

int tokenizeData(unsigned char *buffer, int buffer_len, char *separator, char **tokens, int *numTokens) {
	if (!buffer || buffer_len < 0 || !separator || !tokens || !numTokens) {
		fprintf(stderr, "Invalid arguments\n");
		return 0;
	}

	int sep_len = 2;
	int last_sep = 0;

	// if there exists a separator in the buffer
	// the first token is from the beginning of the buffer to the first separator (include the separator)
	// the second token is after the first separator to the second separator (include the separator)
	// and so on

	for (int i = 0; i < buffer_len; ++i) {
		if (memcmp(buffer + i, separator, sep_len) == 0) {
			// printf("Found separator at index %d\n", i);
			memcpy(tokens[*numTokens], buffer + last_sep, i - last_sep + sep_len);
			tokens[*numTokens][i - last_sep + sep_len] = '\0';
			++(*numTokens);
			last_sep = i + sep_len;
		}
	}

	// if the data didn't end with a separator
	// if (last_sep != buffer_len) {
	// 	printf("Last separator at index %d\n", last_sep);
	// 	printf("Buffer does not end with a separator\n");
	// 	printf("Dropped the last token\n");
	// }

	return 0;

}

int writeNormalDataCSVHeaders(char* writingBuffer) {
	if (!writingBuffer) {
		fprintf(stderr, "Invalid argument\n");
		return 0;
	}

	sprintf(writingBuffer, "count,srcaddr,dstaddr,nexthop,dPkts,dOctets,srcport,dstport,prot,tos,padding\n");

	return 0;
}

int extractNormalDataToCSV(char* writingBuffer, char* buffer, int len) {
	if (!writingBuffer || !buffer || len < normal_field_sum_size/8) {
		fprintf(stderr, "Invalid arguments for extractNormalDataToCSV\n");
		return 0;
	}

	int offset = 0;
	int i, b;

	uint32_t value = 0;
	for(i = 0; i < normal_field_sizes_length-1; i++) {
		for(b = normal_field_sizes[i]/8; b > 0; --b) {
			value <<= 8;
			value |= buffer[offset++];
		}
		sprintf(writingBuffer + offset, "%u,", value);
	}
	sprintf(writingBuffer + offset, "\n");
}

int writeNetFlowDataCSVHeaders(char* writingBuffer) {
	if (!writingBuffer) {
		fprintf(stderr, "Invalid argument for writeNetFlowDataCSVHeaders\n");
		return 0;
	}

	sprintf(writingBuffer, "version,count,sys_uptime,unix_secs,unix_nsecs,flow_sequence,engine_type,engine_id,sampling_interval\n");

	return 0;
}

int extractNetFlowHeaderToCSV(char* writingBuffer, char* buffer, int len) {
	if (!writingBuffer || !buffer || len < netflow_header_sum_size/8) {
		fprintf(stderr, "Invalid arguments for extractNetFlowHeaderToCSV\n");
		return 0;
	}

	int offset = 0;
	int i, b;

	uint32_t value = 0;
	for(i = 0; i < netflow_header_array_length-1; i++) {
		for(b = header_field_sizes[i]/8; b > 0; --b) {
			value <<= 8;
			value |= buffer[offset++];
		}
		sprintf(writingBuffer + offset, "%u,", value);
	}
	sprintf(writingBuffer + offset, "\n");
	return offset;
}

int extractNetFlowRecordToCSV(char* writingBuffer, char* buffer, int len) {
	if (!writingBuffer || !buffer || len < netflow_record_sum_size/8) {
		fprintf(stderr, "Invalid arguments for extractNetFlowRecordToCSV\n");
		return 0;
	}

	int offset = 0;
	int i, b;

	uint32_t value = 0;
	for(i = 0; i < netflow_record_array_length-1; i++) {
		for(b = record_field_sizes[i]/8; b > 0; --b) {
			value <<= 8;
			value |= buffer[offset++];
		}
		sprintf(writingBuffer + offset, "%u,", value);
	}
	sprintf(writingBuffer + offset, "\n");
	return offset;
}

void getNetFlowRecordCountFromHeader(char* buffer, int* recordCount) {
	recordCount = (buffer[2] << 8) | buffer[3];
}

int extractFullNetFlowPacketToCSV(char* writingBuffer, char* buffer, int len) {
	if (!writingBuffer || !buffer || len < netflow_header_sum_size/8) {
		fprintf(stderr, "Invalid arguments\n");
		return 0;
	}

	int offset = 0;

	offset += extractNetFlowHeaderToCSV(writingBuffer, buffer, len);

	int recordCount = 0;
	getNetFlowRecordCountFromHeader(buffer, &recordCount);

	for(int i = 0; i < recordCount; i++) {
		offset += extractNetFlowRecordToCSV(writingBuffer + offset, 
			buffer + netflow_header_sum_size/8 + i * netflow_record_sum_size/8, 
			len - (netflow_header_sum_size/8 + i * netflow_record_sum_size/8)
		);
	}
	return offset;
}