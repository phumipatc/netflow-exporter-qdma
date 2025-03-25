#include "data_manager.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper macro to extract a field dynamically
#define EXTRACT_FIELD(TYPE, DATA, FIELD, FIELD_SIZES)           \
	if (bit_offset + FIELD_SIZES[i] <= total_bits) {            \
		uint64_t value = 0;                                     \
		for (int b = 0; b < FIELD_SIZES[i]; ++b) {              \
			value <<= 1;                                        \
			value |= (buffer[(bit_offset + b) / 8] >> (7 - ((bit_offset + b) % 8))) & 1; \
		}                                                       \
		DATA->FIELD = (TYPE)value;                            \
		bit_offset += FIELD_SIZES[i++];                         \
	} else {                                                    \
		fprintf(stderr, "Buffer size too small\n");             \
		return -1;                                              \
	}

// convert value to char array stored in buffer and return the number of characters written
int toString(unsigned int value, char *buffer, char *optional) {
	return sprintf(buffer, "%u%s", value, optional);
}

int tokenizeData(unsigned char *buffer, int buffer_len, char *separator, char **tokens, int *numTokens) {
	if (!buffer || buffer_len < 0 || !separator || !tokens || !numTokens) {
		fprintf(stderr, "Invalid arguments\n");
		return -1;
	}

	int sep_len = strlen(separator);
	int last_sep = 0;

	// if there exists a separator in the buffer
	// the first token is from the beginning of the buffer to the first separator (include the separator)
	// the second token is after the first separator to the second separator (include the separator)
	// and so on

	for (int i = 0; i < buffer_len; ++i) {
		if (strncmp(buffer + i, separator, sep_len) == 0) {
			free(tokens[*numTokens]);
			tokens[*numTokens] = malloc(i - last_sep + sep_len + 1);
			strncpy(tokens[*numTokens], buffer + last_sep, i - last_sep + sep_len);
			tokens[*numTokens][i - last_sep + sep_len] = '\0';
			++(*numTokens);
			last_sep = i + sep_len;
		}
	}

	// if the data didn't end with a separator, drop the last token
	if (last_sep != buffer_len) {
		printf("Buffer does not end with a separator\n");
		printf("Dropped the last token\n");
	}

	return 0;

}
int extractNormalData(normal_data_t *data, char *buffer, int len) {
	if (!data || !buffer || len < 0) {
		fprintf(stderr, "Invalid arguments\n");
		return -1;
	}

	int bit_offset = 0;
	int total_bits = len * 8;
	size_t i = 0;

	// TODO: Extract the fields from the buffer and store them in the data structure
	EXTRACT_FIELD(uint16_t, data, count, normal_field_sizes);
	EXTRACT_FIELD(uint32_t, data, srcaddr, normal_field_sizes);
	EXTRACT_FIELD(uint32_t, data, dstaddr, normal_field_sizes);
	EXTRACT_FIELD(uint32_t, data, nexthop, normal_field_sizes);
	EXTRACT_FIELD(uint32_t, data, dPkts, normal_field_sizes);
	EXTRACT_FIELD(uint32_t, data, dOctets, normal_field_sizes);
	EXTRACT_FIELD(uint32_t, data, srcport, normal_field_sizes);
	EXTRACT_FIELD(uint32_t, data, dstport, normal_field_sizes);
	EXTRACT_FIELD(uint8_t, data, prot, normal_field_sizes);
	EXTRACT_FIELD(uint8_t, data, tos, normal_field_sizes);
	EXTRACT_FIELD(uint16_t, data, padding, normal_field_sizes);

	return 0;
}

int extractNetFlowHeader(netflow_header_t *header, char *buffer, int len) {
	if (!header || !buffer || len < 24) {
		fprintf(stderr, "Invalid arguments\n");
		return -1;
	}

	int bit_offset = 0;
	int total_bits = len * 8;
	size_t i = 0;

	EXTRACT_FIELD(uint16_t, header, version, header_field_sizes);
	EXTRACT_FIELD(uint16_t, header, count, header_field_sizes);
	EXTRACT_FIELD(uint32_t, header, sys_uptime, header_field_sizes);
	EXTRACT_FIELD(uint32_t, header, unix_secs, header_field_sizes);
	EXTRACT_FIELD(uint32_t, header, unix_nsecs, header_field_sizes);
	EXTRACT_FIELD(uint32_t, header, flow_sequence, header_field_sizes);
	EXTRACT_FIELD(uint8_t, header, engine_type, header_field_sizes);
	EXTRACT_FIELD(uint8_t, header, engine_id, header_field_sizes);
	EXTRACT_FIELD(uint16_t, header, sampling_interval, header_field_sizes);

	return 0;
}

int extractNetFlowRecord(netflow_flow_record_t *record, char *buffer, int len) {
	if (!record || !buffer || len < 48) {
		fprintf(stderr, "Invalid arguments\n");
		return -1;
	}

	int bit_offset = 0;
	int total_bits = len * 8;
	size_t i = 0;

	EXTRACT_FIELD(uint32_t, record, srcaddr, record_field_sizes);
	EXTRACT_FIELD(uint32_t, record, dstaddr, record_field_sizes);
	EXTRACT_FIELD(uint32_t, record, nexthop, record_field_sizes);
	EXTRACT_FIELD(uint16_t, record, input, record_field_sizes);
	EXTRACT_FIELD(uint16_t, record, output, record_field_sizes);
	EXTRACT_FIELD(uint32_t, record, dPkts, record_field_sizes);
	EXTRACT_FIELD(uint32_t, record, dOctets, record_field_sizes);
	EXTRACT_FIELD(uint32_t, record, First, record_field_sizes);
	EXTRACT_FIELD(uint32_t, record, Last, record_field_sizes);
	EXTRACT_FIELD(uint16_t, record, srcport, record_field_sizes);
	EXTRACT_FIELD(uint16_t, record, dstport, record_field_sizes);
	EXTRACT_FIELD(uint8_t, record, pad1, record_field_sizes);
	EXTRACT_FIELD(uint8_t, record, tcp_flags, record_field_sizes);
	EXTRACT_FIELD(uint8_t, record, prot, record_field_sizes);
	EXTRACT_FIELD(uint8_t, record, tos, record_field_sizes);
	EXTRACT_FIELD(uint16_t, record, src_as, record_field_sizes);
	EXTRACT_FIELD(uint16_t, record, dst_as, record_field_sizes);
	EXTRACT_FIELD(uint8_t, record, src_mask, record_field_sizes);
	EXTRACT_FIELD(uint8_t, record, dst_mask, record_field_sizes);
	EXTRACT_FIELD(uint16_t, record, pad2, record_field_sizes);

	return 0;
}

int extractFullNetflowPacket(full_netflow_packet_t *packet, char *buffer, int len) {
	if (!packet || !buffer || len < 24) {
		fprintf(stderr, "Invalid arguments\n");
		return -1;
	}

	int bit_offset = 0;
	int total_bits = len * 8;
	size_t i = 0;

	if (extractNetFlowHeader(&packet->header, buffer, len) < 0) {
		return -1;
	}

	while (i < packet->header.count) {
		if (extractNetFlowRecord(&packet->records[i], buffer + (bit_offset / 8), len - (bit_offset / 8)) < 0) {
			return -1;
		}
		bit_offset += 48 * 8;
		++i;
	}

	return 0;
}

int convertNormalDataToCSV(normal_data_t *data, char *buffer) {
	if (!data || !buffer) {
		fprintf(stderr, "Invalid arguments\n");
		return -1;
	}

	int offset = 0;

	char comma[] = ",";
	char newline[] = "\n";

	// TODO: Convert the data structure to a CSV string and store it in the buffer
	offset += toString(data->count, buffer + offset, comma);
	offset += toString(data->srcaddr, buffer + offset, comma);
	offset += toString(data->dstaddr, buffer + offset, comma);
	offset += toString(data->nexthop, buffer + offset, comma);
	offset += toString(data->dPkts, buffer + offset, comma);
	offset += toString(data->dOctets, buffer + offset, comma);
	offset += toString(data->srcport, buffer + offset, comma);
	offset += toString(data->dstport, buffer + offset, comma);
	offset += toString(data->prot, buffer + offset, comma);
	offset += toString(data->tos, buffer + offset, comma);
	offset += toString(data->padding, buffer + offset, newline);

	return offset;
}

int convertArrayOfNormalDataToCSV(normal_data_t *data, int numRecords, char *buffer) {
	if (!data || numRecords < 0 || !buffer) {
		fprintf(stderr, "Invalid arguments\n");
		return -1;
	}

	int offset = 0;

	// Add CSV column headers
	offset += sprintf(buffer + offset, "count,srcaddr,dstaddr,nexthop,dPkts,dOctets,srcport,dstport,prot,tos,padding\n");

	for (int i = 0; i < numRecords; ++i) {
		offset += convertNormalDataToCSV(data + i, buffer + offset);
	}

	return offset;
}

int convertFullNetflowPacketToCSV(full_netflow_packet_t *packet, char *buffer) {
	if (!packet || !buffer) {
		fprintf(stderr, "Invalid arguments\n");
		return -1;
	}

	int offset = 0;

	// Add CSV column headers
	offset += sprintf(buffer + offset, "version,count,sys_uptime,unix_secs,unix_nsecs,flow_sequence,engine_type,engine_id,sampling_interval\n");

	char comma[] = ",";
	char newline[] = "\n";

	offset += toString(packet->header.version, buffer + offset, comma);
	offset += toString(packet->header.count, buffer + offset, comma);
	offset += toString(packet->header.sys_uptime, buffer + offset, comma);
	offset += toString(packet->header.unix_secs, buffer + offset, comma);
	offset += toString(packet->header.unix_nsecs, buffer + offset, comma);
	offset += toString(packet->header.flow_sequence, buffer + offset, comma);
	offset += toString(packet->header.engine_type, buffer + offset, comma);
	offset += toString(packet->header.engine_id, buffer + offset, comma);
	offset += toString(packet->header.sampling_interval, buffer + offset, comma);

	// TODO: Convert the records to CSV and store them in the buffer

	return offset;
}