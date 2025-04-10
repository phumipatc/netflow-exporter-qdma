#include "influxdb.hpp" // Ensure you have the influxdb-cpp library and include path configured
#include "db_writer.h"

#include <cstdio>
#include <fcntl.h>

influxdb_cpp::server_info conn = influxdb_cpp::server_info("localhost", 8086, "file_records", "hoshino", "hoshino555", "ms", "_khxc6pgVeJ8hCJsXF3Gr2mqYuuTA9OCqq_AgHNR331lYG1DT_xueBLpxrW1LM_G8FPi-zZ3I9yJt2XJPitbQ==");

void initDBWriter(const char* host, int port, const char* database) {
	// No specific initialization needed for influxdb-cpp
}

void destroyDBWriter() {
	// No specific cleanup needed for influxdb-cpp
}

int logToInfluxDB(const char* fileName, stat_t* stats) {
	using namespace influxdb_cpp;

	int status = builder()
		.meas("file_records")
		.field("file_name", fileName)
		.field("tcp_count", stats->prot_tcp_count)
		.field("udp_count", stats->prot_udp_count)
		.field("icmp_count", stats->prot_icmp_count)
		.field("other_count", stats->prot_other_count)
		.field("sum_dPkts", stats->sum_dPkts)
		.field("sum_dOctets", stats->sum_dOctets)
		.post_http(conn);

	if (status != 0) {
		printf("Error: Unable to write file name to InfluxDB (status: %d)\n", status);
		return -1;
	}

	return 0;
}

int writeToFile(const char* filePath, const char* buffer, size_t size, stat_t* stats) {
	int fd = open(filePath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0) {
		printf("Error: Unable to open %s for writing.\n", filePath);
		return -1;
	}

	write(fd, buffer, size);
	close(fd);

	// return logToInfluxDB("localhost", 8086, "file_records", filePath, stats);
	return 0;
}