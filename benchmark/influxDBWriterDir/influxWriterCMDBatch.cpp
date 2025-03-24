#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <string>
#include <cstdlib> // For system()

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

// Function to write points to a file in line protocol format and execute a command to insert them
PerformanceMetrics writeToInfluxDB(const string& database, size_t targetPoints, size_t pointSize, size_t batchSize) {
    const string measurement = "benchmark2";
    const string filename = "influx_data.txt"; // File to store line protocol data
    string payload = generatePayload(pointSize); // Create a payload of the desired size

    size_t pointsWritten = 0;
    size_t currentBatchSize = 0;

    auto start = high_resolution_clock::now();

    while (pointsWritten < targetPoints) {
		// Open the file to save the data
		ofstream dataFile(filename, ios::trunc);
		if (!dataFile) {
			cerr << "Error: Unable to open " << filename << " for writing." << endl;
			exit(EXIT_FAILURE);
		}

        while (currentBatchSize < batchSize && pointsWritten + currentBatchSize < targetPoints) {
            currentBatchSize++;
            // Write a data point in line protocol format
            dataFile << measurement << ",tag1=value payload=\"" << payload << "\"\n";
        }

		dataFile.close();

		// Use `influx` CLI to write data from the file
		string command = "influx write -b " + database + " -o Capstone -p ms -f " + filename;
		int status = system(command.c_str());
		if (status != 0) {
			cerr << "Error: Failed to write data to InfluxDB. CLI returned status " << status << endl;
			exit(EXIT_FAILURE);
		}

        pointsWritten += currentBatchSize;
        currentBatchSize = 0; // Reset batch size
    }

    auto end = high_resolution_clock::now();
    double elapsedTime = duration<double>(end - start).count();
    double throughput = pointsWritten / elapsedTime;

    return {elapsedTime, throughput, pointsWritten};
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        cerr << "Usage: " << argv[0] << " <target_points> <num_trials> <point_size> <batch_size>" << endl;
        return EXIT_FAILURE;
    }

    size_t targetPoints = static_cast<size_t>(stoull(argv[1])); // Convert target points to size_t
    int numTrials = atoi(argv[2]);                             // Convert number of trials to integer
    size_t pointSize = static_cast<size_t>(stoull(argv[3]));   // Target size of each point in bytes
    size_t batchSize = static_cast<size_t>(stoull(argv[4]));   // Batch size
    const string database = "benchmark";                      // Database name

    // Open performance summary file
    ofstream summaryFile("influxdb_performance_summary.txt");
    if (!summaryFile) {
        cerr << "Error: Unable to open influxdb_performance_summary.txt for writing." << endl;
        return EXIT_FAILURE;
    }

    // Stream output to both console and file
    auto writeOutput = [&](const string& output) {
        cout << output;
        summaryFile << output;
    };

    writeOutput("Target Points: " + to_string(targetPoints) + "\n");
    writeOutput("Number of Trials: " + to_string(numTrials) + "\n");
    writeOutput("Point Size: " + to_string(pointSize) + " bytes\n");
    writeOutput("Batch Size: " + to_string(batchSize) + " points\n\n");

    vector<PerformanceMetrics> metrics;

    for (int trial = 1; trial <= numTrials; ++trial) {
        writeOutput("Trial " + to_string(trial) + ": Writing " + to_string(targetPoints) + " points to InfluxDB...\n");

        PerformanceMetrics result = writeToInfluxDB(database, targetPoints, pointSize, batchSize);
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
    summary += "Average Throughput (Points/second): " + to_string(totalThroughput / numTrials) + " points/second\n";
	summary += "Average Throughput (MB/second): " + to_string((totalThroughput * pointSize) / (1024 * 1024) / numTrials) + " MB/second\n";

    writeOutput(summary);

    summaryFile.close();
    return EXIT_SUCCESS;
}
