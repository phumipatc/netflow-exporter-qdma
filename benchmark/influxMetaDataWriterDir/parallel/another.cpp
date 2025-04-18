#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <chrono>
#include <iomanip>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <functional>
#include <sys/stat.h>
#include <fcntl.h>
#include "influxdb.hpp" // Ensure you have the influxdb-cpp library and include path configured

using namespace std;
using namespace std::chrono;

// Struct to store performance metrics
struct PerformanceMetrics {
    double elapsedTime;        // Time taken for the write
    double throughput;         // Throughput in points per second
    size_t pointsWritten;      // Total data points written
};

// Thread pool implementation
class ThreadPool {
    vector<thread> workers;
    queue<function<void()>> tasks;
    mutex queueMutex;
    condition_variable condition;
    bool stop = false;

public:
    explicit ThreadPool(size_t threads) {
        for (size_t i = 0; i < threads; ++i) {
            workers.emplace_back([this] {
                for (;;) {
                    function<void()> task;
                    {
                        unique_lock<mutex> lock(this->queueMutex);
                        this->condition.wait(lock, [this] { return this->stop || !this->tasks.empty(); });
                        if (this->stop && this->tasks.empty()) return;
                        task = move(this->tasks.front());
                        this->tasks.pop();
                    }
                    task();
                }
            });
        }
    }

    template <class F>
    void enqueue(F&& task) {
        {
            unique_lock<mutex> lock(queueMutex);
            tasks.emplace(forward<F>(task));
        }
        condition.notify_one();
    }

    ~ThreadPool() {
        {
            unique_lock<mutex> lock(queueMutex);
            stop = true;
        }
        condition.notify_all();
        for (thread& worker : workers) worker.join();
    }
};

// Generate a dummy string to fill a specified size
void generatePayload(size_t payloadSize, string& payload) {
    payload.assign(payloadSize, 'A'); // Fill the payload with repeated 'A' characters
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

    ThreadPool fileWritePool(4); // Create a pool with 4 threads for file writing
    ThreadPool loggingPool(2);  // Separate pool for logging

    auto start = high_resolution_clock::now();

    while (pointsWritten < targetPoints) {
        string fileName = "/mnt/temp/data_batch_" + to_string(pointsWritten / batchSize) + ".txt";
        int fd = open(fileName.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd < 0) {
            cerr << "Error: Unable to open " << fileName << " for writing." << endl;
            exit(EXIT_FAILURE);
        }

        for (size_t i = 0; i < batchSize && pointsWritten < targetPoints; ++i, ++pointsWritten) {
            generatePayload(pointSize, payload);
            memcpy(&buffer[i * (pointSize + 1)], payload.data(), pointSize);
            buffer[i * (pointSize + 1) + pointSize] = '\n';
        }

        fileWritePool.enqueue([fd, buffer] {
            write(fd, buffer.data(), buffer.size());
            close(fd);
        });

        loggingPool.enqueue([host, port, database, fileName] {
            logFileNamesToInfluxDB(host, port, database, fileName);
        });
    }

    // Destruction of ThreadPool ensures all tasks are completed
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

    for (int trial = 1; trial <= numTrials; ++trial) {
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
    summary += "Average Throughput (size/second): " + to_string(((double)totalThroughput * pointSize) / numTrials / 1e6) + " Megabytes/second\n";

    writeOutput(summary);

    summaryFile.close();
    return EXIT_SUCCESS;
}
