#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <cstring>
#include <iomanip>

using namespace std;
using namespace std::chrono;

// Function to write data to file until the target size is reached
struct PerformanceMetrics {
    double elapsedTime;        // Time taken for the write
    double throughput;         // Throughput in bytes per second
    size_t writeCount;         // Number of buffer writes
    size_t totalDataWritten;   // Total data written in bytes
};

PerformanceMetrics writeToFile(const string& filename, size_t targetSize, size_t bufferSize) {
    // Create buffer with size around 1464 bytes
    vector<char> buffer(bufferSize, 'A'); // Fill with dummy data ('A')
    buffer[bufferSize - 1] = '\n';        // Add newline character at the end
    vector<char> allBuffer(((targetSize + bufferSize-1) / bufferSize) * bufferSize);

    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "Error: Unable to open file for writing: " << filename << endl;
        exit(EXIT_FAILURE);
    }

    size_t written = 0;
    size_t writeCount = 0;
    auto start = high_resolution_clock::now();

    while (written < targetSize) {
        memcpy(allBuffer.data() + written, buffer.data(), buffer.size());
        written += buffer.size();
        ++writeCount;
    }

    outFile.write(allBuffer.data(), targetSize);

    outFile.close();
    auto end = high_resolution_clock::now();

    double elapsedTime = duration<double>(end - start).count(); // Time in seconds
    double throughput = written / elapsedTime;                 // Throughput (bytes per second)

    return {elapsedTime, throughput, writeCount, written};
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <target_size_in_bytes> <num_trials>" << endl;
        return EXIT_FAILURE;
    }

    size_t targetSize = static_cast<size_t>(stoull(argv[1])); // Convert target size to size_t
    int numTrials = atoi(argv[2]);                           // Convert number of trials to integer
    size_t bufferSize = 1464;                                // Buffer size

    // Open performance summary file for writing
    ofstream summaryFile("performance_summary.txt");
    if (!summaryFile) {
        cerr << "Error: Unable to open performance_summary.txt for writing." << endl;
        return EXIT_FAILURE;
    }

    // Stream to write to both console and file
    auto writeOutput = [&](const string& output) {
        cout << output;
        summaryFile << output;
    };

    // Write header information
    writeOutput("Target File Size: " + to_string(targetSize) + " bytes\n");
    writeOutput("Number of Trials: " + to_string(numTrials) + "\n");
    writeOutput("Buffer Size: " + to_string(bufferSize) + " bytes\n\n");

    vector<PerformanceMetrics> metrics; // Store metrics for each trial

    for (int trial = 1; trial <= numTrials; ++trial) {
        string filename = "/media/hoshino/nvme/test/output_trials/output_trial_" + to_string(trial) + ".bin";

        writeOutput("Trial " + to_string(trial) + ": Writing to " + filename + "...\n");
        PerformanceMetrics result = writeToFile(filename, targetSize, bufferSize);
        metrics.push_back(result);

        writeOutput("Elapsed Time: " + to_string(result.elapsedTime) + " seconds\n");
        writeOutput("Throughput: " + to_string(result.throughput / (1024 * 1024)) + " MB/s\n");
        writeOutput("Write Count: " + to_string(result.writeCount) + "\n");
        writeOutput("Total Data Written: " + to_string(result.totalDataWritten) + " bytes\n\n");
    }

    // Calculate and display average metrics
    double totalElapsedTime = 0;
    double totalThroughput = 0;
    size_t totalWrites = 0;
    size_t totalData = 0;

    for (const auto& m : metrics) {
        totalElapsedTime += m.elapsedTime;
        totalThroughput += m.throughput;
        totalWrites += m.writeCount;
        totalData += m.totalDataWritten;
    }

    string summary = "=== Performance Summary ===\n";
    summary += "Total Data Written Across All Trials: " + to_string(totalData) + " bytes\n";
    summary += "Average Elapsed Time: " + to_string(totalElapsedTime / numTrials) + " seconds\n";
    summary += "Average Throughput: " + to_string((totalThroughput / numTrials) / (1024 * 1024)) + " MB/s\n";
    summary += "Total Write Count Across All Trials: " + to_string(totalWrites) + "\n";

    writeOutput(summary);

    summaryFile.close();
    return EXIT_SUCCESS;
}

