#include<vector>
#include<iostream>
#include <chrono>
#include "read.hpp"
#include "distanceMetrics.hpp"
#include "kmeans.hpp"

int main() {
    KmeansParser::Reader reader("letter.txt");
    std::vector<std::vector<double>> points = reader.readAndParse();
    DM::DistanceMetrics distance_metrics;
    Kmeans::Kmeans kmeans;
    int iterations = 0;
    int k = 16;
    std::cout << "Starting" << "\n";
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
    std::cout << "Finished!" << "\n";
    std::cout << "Took " << iterations << " iterations!\n";
    std::cout << "Execution time: " << elapsed.count() << " seconds\n";
};