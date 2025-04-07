#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include <stdint.h>

// typedef struct {
// 	// TODO: Define the structure of the normal data
// 	// srcaddr, dstaddr, nexthop, dPkts, dOctets, srcport, dscport, prot, tos
// 	uint32_t	srcaddr;
// 	uint32_t	dstaddr;
// 	uint32_t	nexthop;
// 	uint32_t	dPkts;
// 	uint32_t	dOctets;
// 	uint16_t	srcport;
// 	uint16_t	dstport;
// 	uint8_t		prot;
// 	uint8_t		tos;
// 	uint16_t	padding;
// } normal_data_t;

static const int normal_field_sizes_length = 10;
static const uint8_t normal_field_sizes[] = {
	32, 32, 32, 32, 32, 16, 16, 8, 8, 16
};
static const int normal_field_sum_size = 32 + 32 + 32 + 32 + 32 + 16 + 16 + 8 + 8 + 16;
static const int normal_field_skip_mark[] = {
	// skipping the padding
	0, 0, 0, 0, 0, 0, 0, 0, 0, 1
};

// typedef struct {
// 	uint32_t	srcaddr;
// 	uint32_t	dstaddr;
// 	uint32_t	nexthop;
// 	uint16_t	input;
// 	uint16_t	output;
// 	uint32_t	dPkts;
// 	uint32_t	dOctets;
// 	uint32_t	First;
// 	uint32_t	Last;
// 	uint16_t	srcport;
// 	uint16_t	dstport;
// 	uint8_t		pad1;
// 	uint8_t		tcp_flags;
// 	uint8_t		prot;
// 	uint8_t		tos;
// 	uint16_t	src_as;
// 	uint16_t	dst_as;
// 	uint8_t		src_mask;
// 	uint8_t		dst_mask;
// 	uint16_t	pad2;
// } netflow_flow_record_t;

static const int netflow_record_array_length = 19;
static const uint8_t record_field_sizes[] = {
	32, 32, 32, 16, 16, 32, 32, 32, 32, 16, 16, 8, 8, 8, 16, 16, 8, 8, 16
};
static const int netflow_record_sum_size = 32 + 32 + 32 + 16 + 16 + 32 + 32 + 32 + 32 + 16 + 16 + 8 + 8 + 8 + 16 + 16 + 8 + 8 + 16;
static const int netflow_record_skip_mark[] = {
	// skipping the padding
	0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1
};

int tokenizeData(unsigned char *buffer, int buffer_len, char *separator, char **tokens, int *numTokens);

void writeNormalDataCSVHeaders(char *writingBuffer, int *writingOffset);
void extractNormalDataToCSV(char *writingBuffer, int *writingOffset, char *data, int len);

void writeNetFlowRecordCSVHeaders(char *writingBuffer, int *writingOffset);
void extractNetFlowRecordToCSV(char *writingBuffer, int *writingOffset, char *buffer, int len);

#endif // DATA_MANAGER_H