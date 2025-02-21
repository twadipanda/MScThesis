#include "main.decl.h"

#include "main.h"
// #include "distanceMetrics.h"
#include "kmeans.decl.h"
#include "kmeans.h"

#include<vector>
#include<iostream>
#include <chrono>
#include "read.h"

/* readonly */ CProxy_Main mainProxy;
int numElements = 1000;
std::chrono::_V2::system_clock::time_point start;
int counter = 0;
int maxCompute;
std::vector<std::vector<double>> distances;
std::vector<std::vector<double>> points;
std::vector<std::vector<double>> centers;
CProxy_Kmeans kmeansArray = CProxy_Kmeans::ckNew(numElements);


// Entry point of Charm++ application
Main::Main(CkArgMsg* msg) {
    mainProxy = thisProxy;
    int k = 26;
    int iterations = 0;
    int proxies = 0;
    numElements = 1000;
    // EuclideanDistance distance_metrics;
    KmeansParser::Reader reader("letter.txt");
    Kmeans kmeans;
    points = reader.readAndParse();
    centers = kmeans.getInitialCenters(points, k);
    maxCompute = points.size() * centers.size();
    distances.resize(points.size());
    // CProxy_Kmeans kmeansArray = CProxy_Kmeans::ckNew(numElements);
    start = std::chrono::high_resolution_clock::now();
    kmeansArray[proxies].computeDistance(points, centers);
    // std::vector<std::vector<double>> distances = kmeans.computeDistance(points, centers, &DistanceMetrics::euclideanDistance, distance_metrics);
    // std::vector<std::vector<double>> new_centers = kmeans.computeNewCenters(points, distances, k);
    // while (centers != new_centers) {
    //     iterations++;
    //     distances = kmeans.computeDistance(points, new_centers, &DistanceMetrics::euclideanDistance, distance_metrics);
    //     centers = new_centers;
    //     new_centers = kmeans.computeNewCenters(points, distances, k);
    // }
    
    
    // int index = 0;
    // for (std::vector<double> point : points) {
    //     for (std::vector<double> center : centers) {
    //         if (index == 999) {
    //             index = 0;
    //         }
    //         distanceMetricsArray[index].euclideanDistance(point, center);
    //         index++;
    //     }
    // }
}


// Constructor needed for chare object migration (ignore for now)
// NOTE: This constructor does not need to appear in the ".ci" file
Main::Main(CkMigrateMessage* msg) { }

void Main::finished(std::vector<double>& distance, int index, int isFinal) {
    CkPrintf("Finished called %d by index %d\n", CkMyPe(), index);
    distances[index] = distance;
    if (isFinal) {
        std::cout << "Another Iteration!\n";
        Kmeans kmeans;
        std::vector<std::vector<double>> new_centers = kmeans.computeNewCenters(points, distances, 26);
        if (centers != new_centers) {
            kmeansArray[0].computeDistance(points, new_centers);
            centers = new_centers;
        }
        else {
            done();
        }
    }
    // CkPrintf("Got value %f from index %d on processor %d\n", value, index, CkMyPe());
    // counter++;
    // if (counter == maxCompute) {
    //     done();
    // }
}


// When called, the "done()" entry method will cause the program
//   to exit.
void Main::done() {
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Finished!" << "\n";
    // std::cout << "Took " << iterations << " iterations!\n";
    std::cout << "Execution time: " << elapsed.count() << " seconds\n";
    CkExit();
}


#include "main.def.h"
