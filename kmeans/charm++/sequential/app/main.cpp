/**
 * @file main.cpp
 * @brief Main entry point for the K-Means clustering algorithm in C++.
 *
 * This file drives the K-Means clustering process by reading data points from a file,
 * initializing centers, and iterating until convergence. It measures and outputs the
 * execution time.
 */

 #include <vector>
 #include <iostream>
 #include <chrono>
 #include <string>
 #include "read.hpp"
 #include "distanceMetrics.hpp"
 #include "kmeans.hpp"
 
 /**
  * @brief Main function to execute K-Means clustering.
  * @return 0 on successful execution.
  */
 int main(int argc, char* argv[]) {
    std::string fileName = argv[1];
    KmeansParser::Reader reader(fileName);
    std::vector<std::vector<double>> points = reader.readAndParse();
    DM::DistanceMetrics distance_metrics;
    Kmeans::Kmeans kmeans;
    int iterations = 0;
    int k = std::stoi(argv[2]);
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<std::vector<double>> centers = kmeans.getInitialCenters(points, k);
    std::vector<std::vector<double>> distances = kmeans.computeDistance(points, centers, &DM::DistanceMetrics::euclideanDistance, distance_metrics);
    std::vector<std::vector<double>> new_centers = kmeans.computeNewCenters(points, distances, k);
    while (centers != new_centers) {
        iterations++;
        distances = kmeans.computeDistance(points, new_centers, &DM::DistanceMetrics::euclideanDistance, distance_metrics);
        centers = new_centers;
        new_centers = kmeans.computeNewCenters(points, distances, k);
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    // std::cout << "Took " << iterations << " iterations!\n";
    std::cout << elapsed.count();
    return 0;
 }