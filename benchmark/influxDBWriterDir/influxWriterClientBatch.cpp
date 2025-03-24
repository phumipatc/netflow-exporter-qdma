#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <string>
#include "influxdb.hpp" // Ensure you have the influxdb-cpp library and include path configured

using namespace std;
using namespace std::chrono;

// Struct to store performance metrics
struct PerformanceMetrics {
	double elapsedTime;        // Time taken for the write
	double throughput;         // Throughput in points per second
	size_t pointsWritten;      // Total data points written
};

// Generate a dummy string to fill a specified size
string generatePayload(size_t payloadSize) {
	string payload(payloadSize, 'A'); // Fill the payload with repeated 'A' characters
	return payload;
}

// Function to write points to InfluxDB in batches
PerformanceMetrics writeToInfluxDB(const string& host, int port, const string& database, size_t targetPoints, size_t pointSize, size_t batchSize) {
	using namespace influxdb_cpp;

	// InfluxDB connection parameters
	auto conn = influxdb_cpp::server_info(host, port, database, "hoshino", "hoshino555", "ms", "_khxc6pgVeJ8hCJsXF3Gr2mqYuuTA9OCqq_AgHNR331lYG1DT_xueBLTpxrW1LM_G8FPi-zZ3I9yJt2XJPitbQ==");

	// Create payload to match the specified point size
	string payload = generatePayload(pointSize);
	const string measurement = "benchmark2";

	size_t pointsWritten = 0;
	size_t currentBatchSize = 0;

	auto start = high_resolution_clock::now();

	while (pointsWritten < targetPoints) {
		influxdb_cpp::builder builder;
		influxdb_cpp::detail::ts_caller *caller = nullptr;

		auto influxBuilder = influxdb_cpp::builder();
		while(currentBatchSize < batchSize && pointsWritten + currentBatchSize < targetPoints) {
			currentBatchSize++;

			if (caller) {
				caller = &caller->meas(measurement).tag("tag1","value").field("payload", payload);
			} else {
				caller = &builder.meas(measurement).tag("tag1","value").field("payload", payload);
			}
		}

		// When batch reaches batch size, post the data in InfluxDB
		int status = -1;
		string resp;
		if (caller) {
			status = caller->post_http(conn, &resp);
		} else {
			cerr << "Error: No data points to write." << endl;
		}

		if (status != 0) {
			cerr << "Error writing to InfluxDB (status: " << status << ")" << endl;
			cerr << "Response: " << resp << endl;
			exit(EXIT_FAILURE);
		}

		// cerr << "Response: " << resp << endl;

		pointsWritten += currentBatchSize;
		currentBatchSize = 0;
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
	size_t batchSize = static_cast<size_t>(stoull(argv[6]));   // Batch size
	const string database = "benchmark";                      // Database name

	// Open performance summary file
	ofstream summaryFile("influxdb_performance_client_batch_summary.txt");
	if (!summaryFile) {
		cerr << "Error: Unable to open influxdb_performance_client_batch_summary.txt for writing." << endl;
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
	writeOutput("Batch Size: " + to_string(batchSize) + " points\n\n");

	vector<PerformanceMetrics> metrics;

	for (int trial = 1; trial <= numTrials; ++trial) {
		writeOutput("Trial " + to_string(trial) + ": Writing " + to_string(targetPoints) + " points to InfluxDB...\n");

		PerformanceMetrics result = writeToInfluxDB(influxHost, influxPort, database, targetPoints, pointSize, batchSize);
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
	summary += "Average Throughput (points/second): " + to_string(totalThroughput / numTrials) + " points/second\n";
	summary += "Average Throughput (size/second): " + to_string((totalThroughput * pointSize) / numTrials) + " bytes/second\n";

	writeOutput(summary);

	summaryFile.close();
	return EXIT_SUCCESS;
}
