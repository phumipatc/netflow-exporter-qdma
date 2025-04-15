#include "influxdb.hpp" // Ensure you have the influxdb-cpp library and include path configured
#include "db_writer.h"

#include <cstdio>
#include <fcntl.h>
#include <sqlite3.h>

influxdb_cpp::server_info conn = influxdb_cpp::server_info("localhost", 8086, "file_records", "hoshino", "hoshino555", "ms", "_khxc6pgVeJ8hCJsXF3Gr2mqYuuTA9OCqq_AgHNR331lYG1DT_xueBLpxrW1LM_G8FPi-zZ3I9yJt2XJPitbQ==");

sqlite3* db = nullptr;

void initDBWriter(const char* host, int port, const char* database) {
	// No specific initialization needed for influxdb-cpp

	int rc = sqlite3_open(database, &db);
	if (rc) {
		printf("Error: Can't open SQLite database: %s\n", sqlite3_errmsg(db));
		db = nullptr;
	} else {
		const char* createTableSQL = R"SQL(
			CREATE TABLE IF NOT EXISTS file_records (
				id INTEGER PRIMARY KEY AUTOINCREMENT,
				file_name TEXT NOT NULL,
				count INTEGER,
				prot_tcp_count INTEGER,
				prot_udp_count INTEGER,
				prot_icmp_count INTEGER,
				prot_other_count INTEGER,
				sum_dPkts INTEGER,
				sum_dOctets INTEGER
			);
		)SQL";

		char* errMsg = nullptr;
		rc = sqlite3_exec(db, createTableSQL, nullptr, nullptr, &errMsg);
		if (rc != SQLITE_OK) {
			printf("Error: Can't create table: %s\n", errMsg);
			sqlite3_free(errMsg);
		}
	}
}

void destroyDBWriter() {
	// No specific cleanup needed for influxdb-cpp

	if (db) {
		sqlite3_close(db);
		db = nullptr;
	}
}

int logToSQLite(const char* fileName, stat_t* stats) {
	if (!db) {
		printf("Error: SQLite database not initialized.\n");
		return -1;
	}

	const char* insertSQL = R"SQL(
		INSERT INTO file_records (
			file_name, count, prot_tcp_count, prot_udp_count, prot_icmp_count, prot_other_count, sum_dPkts, sum_dOctets
		) VALUES (?, ?, ?, ?, ?, ?, ?, ?);
	)SQL";

	sqlite3_stmt* stmt = nullptr;
	int rc = sqlite3_prepare_v2(db, insertSQL, -1, &stmt, nullptr);
	if (rc != SQLITE_OK) {
		printf("Error: Can't prepare SQLite statement: %s\n", sqlite3_errmsg(db));
		return -1;
	}

	sqlite3_bind_text(stmt, 1, fileName, -1, SQLITE_STATIC);
	sqlite3_bind_int(stmt, 2, stats->count);
	sqlite3_bind_int(stmt, 3, stats->prot_tcp_count);
	sqlite3_bind_int(stmt, 4, stats->prot_udp_count);
	sqlite3_bind_int(stmt, 5, stats->prot_icmp_count);
	sqlite3_bind_int(stmt, 6, stats->prot_other_count);
	sqlite3_bind_int64(stmt, 7, stats->sum_dPkts);
	sqlite3_bind_int64(stmt, 8, stats->sum_dOctets);

	rc = sqlite3_step(stmt);
	if (rc != SQLITE_DONE) {
		printf("Error: Can't execute SQLite statement: %s\n", sqlite3_errmsg(db));
	}

	sqlite3_finalize(stmt);
	return rc == SQLITE_DONE ? 0 : -1;
}

// int logToInfluxDB(const char* fileName, stat_t* stats) {
// 	using namespace influxdb_cpp;

// 	int status = builder()
// 		.meas("file_records")
// 		.field("file_name", fileName)
// 		.field("count", stats->count)
// 		.field("tcp_count", stats->prot_tcp_count)
// 		.field("udp_count", stats->prot_udp_count)
// 		.field("icmp_count", stats->prot_icmp_count)
// 		.field("other_count", stats->prot_other_count)
// 		.field("sum_dPkts", stats->sum_dPkts)
// 		.field("sum_dOctets", stats->sum_dOctets)
// 		.post_http(conn);

// 	if (status != 0) {
// 		printf("Error: Unable to write file name to InfluxDB (status: %d)\n", status);
// 		return -1;
// 	}

// 	return 0;
// }

int writeToFile(const char* filePath, const char* buffer, size_t size, stat_t* stats) {
	int fd = open(filePath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0) {
		printf("Error: Unable to open %s for writing.\n", filePath);
		return -1;
	}

	write(fd, buffer, size);
	close(fd);

	// return logToInfluxDB("localhost", 8086, "file_records", filePath, stats);
	// return logToSQLite(filePath, stats);
	return 0;
}