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
	*writingOffset += sprintf(writingBuffer, "srcaddr,dstaddr,nexthop,dPkts,dOctets,srcport,dstport,prot,tos\n");
}

void extractNormalDataToCSV(char* writingBuffer, int *writingOffset, char* buffer, int len, stat_t *stats) {
	int Readingoffset = 0;
	int i, b;

	uint32_t value = 0;
	for(i = 0; i < normal_field_sizes_length-1; i++) {
		for(b = normal_field_sizes[i]/8; b > 0; --b) {
			value <<= 8;
			value |= buffer[Readingoffset++];
		}
		if(normal_field_skip_mark[i]) {
			continue;
		}
		toString(writingBuffer, writingOffset, value, ',');
		if(i == 3) {
			// dPkts
			stats->sum_dPkts += value;
		} else if(i == 4){
			// dOctets
			stats->sum_dOctets += value;
		}else if(i == 7) {
			// prot
			if(value == 6) {
				stats->prot_tcp_count++;
			} else if(value == 17) {
				stats->prot_udp_count++;
			} else if(value == 1) {
				stats->prot_icmp_count++;
			} else {
				stats->prot_other_count++;
			}
		}
	}
	writingBuffer[*writingOffset] = '\n';
	++(*writingOffset);
}

void writeNetFlowRecordCSVHeaders(char* writingBuffer, int *writingOffset) {
	*writingOffset += sprintf(writingBuffer, "srcaddr,dstaddr,nexthop,input,output,dPkts,dOctets,First,Last,srcport,dstport,tcp_flags,prot,tos,src_as,dst_as,src_mask,dst_mask\n");
}

void extractNetFlowRecordToCSV(char* writingBuffer, int *writingOffset, char* buffer, int len, stat_t *stats) {
	int readingOffset = 0;
	int i, b;

	uint32_t value = 0;
	for(i = 0; i < netflow_record_array_length-1; i++) {
		for(b = record_field_sizes[i]/8; b > 0; --b) {
			value <<= 8;
			value |= buffer[readingOffset++];
		}
		if(netflow_record_skip_mark[i]) {
			continue;
		}
		toString(writingBuffer, writingOffset, value, ',');
	}
	writingBuffer[*writingOffset] = '\n';
	++(*writingOffset);
}