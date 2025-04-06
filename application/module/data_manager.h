#ifndef DATA_MANAGER_H
#define DATA_MANAGER_H

#include <stdint.h>

// typedef struct {
// 	// TODO: Define the structure of the normal data
// 	// count, srcaddr, dstaddr, nexthop, dPkts, dOctets, srcport, dscport, prot, tos
// 	uint16_t	count;
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

static const int normal_field_sizes_length = 11;
static const uint8_t normal_field_sizes[] = {
	16, 32, 32, 32, 32, 32, 16, 16, 8, 8, 16
};
static const int normal_field_sum_size = 16 + 32 + 32 + 32 + 32 + 32 + 16 + 16 + 8 + 8 + 16;

// typedef struct {
// 	uint16_t	version;
//     uint16_t	count;
//     uint32_t	sys_uptime;
//     uint32_t	unix_secs;
//     uint32_t	unix_nsecs;
//     uint32_t	flow_sequence;
//     uint8_t		engine_type;
//     uint8_t		engine_id;
//     uint16_t	sampling_interval;

// } netflow_header_t;

static const int netflow_header_array_length = 9;
static const uint8_t header_field_sizes[] = {
	16, 16, 32, 32, 32, 32, 8, 8, 16
};
static const int netflow_header_sum_size = 16 + 16 + 32 + 32 + 32 + 32 + 8 + 8 + 16;

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

// typedef struct {
// 	netflow_header_t header;
// 	netflow_flow_record_t records[32];
// } full_netflow_packet_t;

int tokenizeData(unsigned char *buffer, int buffer_len, char *separator, char **tokens, int *numTokens);

int writeNormalDataCSVHeaders(char *writingBuffer);
int extractNormalDataToCSV(char *buffer, char *data, int len);

int writeNetFlowDataCSVHeaders(char *writingBuffer);
int extractNetFlowHeaderToCSV(char *writingBuffer, char *buffer, int len);
int extractNetFlowRecordToCSV(char *writingBuffer, char *buffer, int len);
int extractFullNetFlowPacketToCSV(char *writingBuffer, char *buffer, int len);
#endif