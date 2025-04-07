#include "influxdb.hpp" // Ensure you have the influxdb-cpp library and include path configured
#include "db_writer.h"

#include <cstdio>
#include <fcntl.h>

influxdb_cpp::server_info conn;

void initDBWriter(const char* host, int port, const char* database) {
	using namespace influxdb_cpp;
	conn = influxdb_cpp::server_info(host, port, database, "hoshino", "hoshino555", "ms", "_khxc6pgVeJ8hCJsXF3Gr2mqYuuTA9OCqq_AgHNR331lYG1DT_xueBLpxrW1LM_G8FPi-zZ3I9yJt2XJPitbQ==");
}

void destroyDBWriter() {
	// No specific cleanup needed for influxdb-cpp
}

int logFileNamesToInfluxDB(const char* fileName) {
	using namespace influxdb_cpp;

	int status = builder()
		.meas("file_records")
		.field("file_name", fileName)
		.post_http(conn);

	if (status != 0) {
		printf("Error: Unable to write file name to InfluxDB (status: %d)\n", status);
		return -1;
	}

	return 0;
}

int writeToFile(const char* filePath, const char* buffer, size_t size) {
	int fd = open(filePath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0) {
		printf("Error: Unable to open %s for writing.\n", filePath);
		return -1;
	}

	write(fd, buffer, size);
	close(fd);

	// return logFileNamesToInfluxDB("localhost", 8086, "file_records", filePath);
	return 0;
}