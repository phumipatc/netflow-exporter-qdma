#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <string>
#include <thread>
#include <cstdio>
#include "influxdb.hpp" // Ensure you have the influxdb-cpp library and include path configured

using namespace std;
using namespace std::chrono;

int trial = 0;

// Struct to store performance metrics
struct PerformanceMetrics {
	double elapsedTime;        // Time taken for the write
	double throughput;         // Throughput in points per second
	size_t pointsWritten;      // Total data points written
};

// Generate a dummy string to fill a specified size
void generatePayload(size_t payloadSize, string& payload) {
	payload.assign(payloadSize, 'A' + trial); // Fill the payload with repeated 'A' characters
}


// Function to write file names to InfluxDB asynchronously
void logFileNamesToInfluxDB(const string& host, int port, const string& database, const string& fileName) {
	using namespace influxdb_cpp;
	auto conn = influxdb_cpp::server_info(host, port, database, "hoshino", "hoshino555", "ms", "_khxc6pgVeJ8hCJsXF3Gr2mqYuuTA9OCqq_AgHNR331lYG1DT_xueBLTpxrW1LM_G8FPi-zZ3I9yJt2XJPitbQ==");

	int status = builder()
		.meas("file_records")
		.field("file_name", fileName)
		.post_http(conn);

	if (status != 0) {
		cerr << "Error writing file name to InfluxDB (status: " << status << ")" << endl;
	}
}

// Function to write points to multiple files and log file names in InfluxDB
PerformanceMetrics writeToFilesAndInfluxDB(const string& host, int port, const string& database, size_t targetPoints, size_t pointSize, size_t batchSize) {
	size_t pointsWritten = 0;

	string buffer(batchSize * (pointSize + 1), '\0');

	string payload;

	auto start = high_resolution_clock::now();

	// Write data in batches, each batch in a new file
	while (pointsWritten < targetPoints) {
		string fileName = "/mnt/temp/data_batch_" + to_string(trial * 10 + pointsWritten / batchSize) + ".txt";
		FILE* outFile = fopen(fileName.c_str(), "w");
		if (outFile == NULL) {
			cerr << "Error: Unable to open " << fileName << " for writing." << endl;
			exit(EXIT_FAILURE);
		}

		for (size_t i = 0; i < batchSize && pointsWritten < targetPoints; ++i, ++pointsWritten) {
			generatePayload(pointSize, payload); // Generate a new payload for each point
			memcpy(&buffer[i * (pointSize + 1)], payload.data(), pointSize);
			buffer[i * (pointSize + 1) + pointSize] = '\n';
		}

		int result = fwrite(buffer.data(), sizeof(char), batchSize * (pointSize + 1), outFile);
		if(ferror(outFile))
			perror("Error occurred: ");
		fclose(outFile);

		logFileNamesToInfluxDB(host, port, database, fileName);
		// std::thread(logFileNamesToInfluxDB, host, port, database, fileName).detach();
	}

	auto end = high_resolution_clock::now();
	double elapsedTime = duration<double>(end - start).count();
	double throughput = pointsWritten / elapsedTime;

	return {elapsedTime, throughput, pointsWritten};
}

int main(int argc, char* argv[]) {
	if (argc != 7) {
		cerr << "Usage: " << argv[0] << " <target_points> <num_trials> <influx_host> <influx_port> <point_size> <batch_size>" << endl;
		return EXIT_FAILURE;
	}

	size_t targetPoints = static_cast<size_t>(stoull(argv[1])); // Convert target points to size_t
	int numTrials = atoi(argv[2]);                             // Convert number of trials to integer
	string influxHost = argv[3];                               // InfluxDB host
	int influxPort = atoi(argv[4]);                            // InfluxDB port
	size_t pointSize = static_cast<size_t>(stoull(argv[5]));   // Target size of each point in bytes
	size_t batchSize = static_cast<size_t>(stoull(argv[6]));   // Number of records per batch
	const string database = "benchmark";                      // Database name

	// Open performance summary file
	ofstream summaryFile("performance_summary.txt");
	if (!summaryFile) {
		cerr << "Error: Unable to open performance_summary.txt for writing." << endl;
		return EXIT_FAILURE;
	}

	// Stream output to both console and file
	auto writeOutput = [&](const string& output) {
		cout << output;
		summaryFile << output;
	};

	writeOutput("Target Points: " + to_string(targetPoints) + "\n");
	writeOutput("Number of Trials: " + to_string(numTrials) + "\n");
	writeOutput("InfluxDB Host: " + influxHost + "\n");
	writeOutput("InfluxDB Port: " + to_string(influxPort) + "\n");
	writeOutput("Point Size: " + to_string(pointSize) + " bytes\n");
	writeOutput("Batch Size: " + to_string(batchSize) + " records\n\n");

	vector<PerformanceMetrics> metrics;

	for (trial = 1; trial <= numTrials; ++trial) {
		writeOutput("Trial " + to_string(trial) + ": Writing " + to_string(targetPoints) + " points in batches of " + to_string(batchSize) + " records per file...\n");

		PerformanceMetrics result = writeToFilesAndInfluxDB(influxHost, influxPort, database, targetPoints, pointSize, batchSize);
		metrics.push_back(result);

		writeOutput("Elapsed Time: " + to_string(result.elapsedTime) + " seconds\n");
		writeOutput("Throughput: " + to_string(result.throughput) + " points/second\n");
		writeOutput("Points Written: " + to_string(result.pointsWritten) + "\n\n");
	}

	// Calculate summary metrics
	double totalElapsedTime = 0;
	double totalThroughput = 0;
	size_t totalPoints = 0;

	for (const auto& m : metrics) {
		totalElapsedTime += m.elapsedTime;
		totalThroughput += m.throughput;
		totalPoints += m.pointsWritten;
	}

	string summary = "=== Performance Summary ===\n";
	summary += "Total Points Written Across All Trials: " + to_string(totalPoints) + "\n";
	summary += "Average Elapsed Time: " + to_string(totalElapsedTime / numTrials) + " seconds\n";
	summary += "Average Throughput: " + to_string(totalThroughput / numTrials) + " points/second\n";
	summary += "Average Throughput (size/second): " + to_string(((double )totalThroughput * pointSize) / numTrials / 1e6) + " Megabytes/second\n";

	writeOutput(summary);

	summaryFile.close();
	return EXIT_SUCCESS;
}
