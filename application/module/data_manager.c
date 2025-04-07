#include "data_manager.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int utoa(unsigned int value, char *buffer, int base) {
	int i = 0;
	int digit;
	if (value == 0) {
		buffer[i++] = '0';
	}
	while (value > 0) {
		digit = value % base;
		buffer[i++] = (digit < 10) ? '0' + digit : 'A' + digit - 10;
		value /= base;
	}
	buffer[i] = '\0';

	// reverse the string
	for (int j = 0; j < i / 2; ++j) {
		char temp = buffer[j];
		buffer[j] = buffer[i - j - 1];
		buffer[i - j - 1] = temp;
	}
	return i;
}

// convert value to char array stored in buffer and return the number of characters written
void toString(char *buffer, int *writingOffset, unsigned int value, char optional) {
	*writingOffset += utoa(value, buffer + *writingOffset, 10);
	if (optional) {
		buffer[*writingOffset] = optional;
		++(*writingOffset);
		buffer[*writingOffset] = '\0';
	}
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

void writeNormalDataCSVHeaders(char* writingBuffer, int *writingOffset) {
	*writingOffset += sprintf(writingBuffer, "count,srcaddr,dstaddr,nexthop,dPkts,dOctets,srcport,dstport,prot,tos,padding\n");
}

void extractNormalDataToCSV(char* writingBuffer, int *writingOffset, char* buffer, int len) {
	int Readingoffset = 0;
	int i, b;

	uint32_t value = 0;
	for(i = 0; i < normal_field_sizes_length-1; i++) {
		for(b = normal_field_sizes[i]/8; b > 0; --b) {
			value <<= 8;
			value |= buffer[Readingoffset++];
		}
		toString(writingBuffer, writingOffset, value, ',');
	}
	writingBuffer[*writingOffset] = '\n';
	++(*writingOffset);
}

void writeNetFlowDataCSVHeaders(char* writingBuffer, int *writingOffset) {
	*writingOffset += sprintf(writingBuffer, "version,count,sys_uptime,unix_secs,unix_nsecs,flow_sequence,engine_type,engine_id,sampling_interval\n");
}

void extractNetFlowHeaderToCSV(char* writingBuffer, int *writingOffset, char* buffer, int len) {
	int readingOffset = 0;
	int i, b;

	uint32_t value = 0;
	for(i = 0; i < netflow_header_array_length-1; i++) {
		for(b = header_field_sizes[i]/8; b > 0; --b) {
			value <<= 8;
			value |= buffer[readingOffset++];
		}
		toString(writingBuffer, writingOffset, value, ',');
	}
	writingBuffer[*writingOffset] = '\n';
	++(*writingOffset);
}

void extractNetFlowRecordToCSV(char* writingBuffer, int *writingOffset, char* buffer, int len) {
	int readingOffset = 0;
	int i, b;

	uint32_t value = 0;
	for(i = 0; i < netflow_record_array_length-1; i++) {
		for(b = record_field_sizes[i]/8; b > 0; --b) {
			value <<= 8;
			value |= buffer[readingOffset++];
		}
		toString(writingBuffer, writingOffset, value, ',');
	}
	writingBuffer[*writingOffset] = '\n';
	++(*writingOffset);
}

void getNetFlowRecordCountFromHeader(char* buffer, int* recordCount) {
	recordCount = (buffer[2] << 8) | buffer[3];
}

void extractFullNetFlowPacketToCSV(char* writingBuffer, int *writingOffset, char* buffer, int len) {
	writeNetFlowDataCSVHeaders(writingBuffer, &writingOffset);

	extractNetFlowHeaderToCSV(writingBuffer, &writingOffset, buffer, len);

	int recordCount = 0;
	getNetFlowRecordCountFromHeader(buffer, &recordCount);

	for(int i = 0; i < recordCount; i++) {
		extractNetFlowRecordToCSV(writingBuffer, &writingOffset, 
			buffer + netflow_header_sum_size/8 + i * netflow_record_sum_size/8, 
			len - (netflow_header_sum_size/8 + i * netflow_record_sum_size/8)
		);
	}
}