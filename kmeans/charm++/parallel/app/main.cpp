#include "main.decl.h"

#include "main.h"
#include "kmeans.decl.h"
#include "kmeans.h"

#include<vector>
#include<iostream>
#include <chrono>
#include "read.h"

/* readonly */ CProxy_Main mainProxy;
int numElements;
std::chrono::_V2::system_clock::time_point start;
int counter;
int maxCompute;
std::vector<std::vector<double>> distances;
std::vector<std::vector<double>> points;
std::vector<std::vector<double>> centers;
std::vector<std::vector<double>> new_centers;
CProxy_Kmeans kmeansArray;
int k;
int iterations;
int timesCalled;


// Entry point of Charm++ application
Main::Main(CkArgMsg* msg) {
    numElements = 100;
    kmeansArray = CProxy_Kmeans::ckNew(numElements);
    counter = 0;
    mainProxy = thisProxy;
    k = 25;
    timesCalled = 0;
    iterations = 1;
    KmeansParser::Reader reader("worms_64d.txt");
    points = reader.readAndParse();
    centers = Kmeans::getInitialCenters(points, k);
    new_centers.resize(k);
    maxCompute = points.size() * centers.size();
    distances.resize(points.size());
    start = std::chrono::high_resolution_clock::now();
    kmeansArray[0].computeDistance(points, centers);
}


// Constructor needed for chare object migration (ignore for now)
// NOTE: This constructor does not need to appear in the ".ci" file
Main::Main(CkMigrateMessage* msg) { }

// void Main::finished(const std::vector<double>& distance, int index) {
//     distances[index] = distance;
//     timesCalled++;
//     if (timesCalled == points.size()) {
//         timesCalled = 0;
//         std::vector<std::vector<double>> new_centers = Kmeans::computeNewCenters(points, distances, k);
//         if (centers != new_centers) {
//             centers = new_centers;
//             iterations++;
//             distances.clear();
//             distances.resize(points.size());
//             kmeansArray[0].computeDistance(points, new_centers);
//         }
//         else {
//             std::cout << centers[0][0] << "\n";
//             std::cout << new_centers[0][0] << "\n";
//             done();
//         }
//     }
// }

void Main::finished(const std::vector<double>& centerPoint, int k_) {
    timesCalled++;
    new_centers[k_] = centerPoint;
    if (timesCalled == k) {
        timesCalled = 0;
        if (centers != new_centers) {
            centers = new_centers;
            iterations++;
            // std::cout << iterations << "\n";
            kmeansArray[0].computeDistance(points, centers);
        }
        else {
            std::cout << centers[0][0] << "\n";
            std::cout << new_centers[0][0] << "\n";
            done();
        }
    }
}


// When called, the "done()" entry method will cause the program
//   to exit.
void Main::done() {
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    // std::cout << "Finished!" << "\n";
    // std::cout << "Took " << iterations << " iterations!\n";
    std::cout << elapsed.count();
    CkExit();
}


#include "main.def.h"
