#ifndef DB_WRITER_H
#define DB_WRITER_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "data_manager.h"

void initDBWriter(const char* host, int port, const char* database);

void destroyDBWriter();

int logToInfluxDB(const char* host, int port, const char* database, const char* fileName, stat_t* stats);

// int logToSQL

int writeToFile(const char* filePath, const char* buffer, size_t size, stat_t* stats);

#ifdef __cplusplus
}
#endif

#endif // DB_WRITER_H