#ifndef DB_WRITER_H
#define DB_WRITER_H

#ifdef __cplusplus
extern "C"
{
#endif

void initDBWriter(const char* host, int port, const char* database);

void destroyDBWriter();

int logFileNamesToInfluxDB(const char* host, int port, const char* database, const char* fileName);

int writeToFile(const char* filePath, const char* buffer, size_t size);

#ifdef __cplusplus
}
#endif

#endif // DB_WRITER_H