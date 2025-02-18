#include "distanceMetrics.decl.h"

#include "distanceMetrics.h"
#include "main.decl.h"

#include <cmath>
#include <vector>

extern CProxy_Main mainProxy;

DistanceMetrics::DistanceMetrics() {};
DistanceMetrics::DistanceMetrics(CkMigrateMessage *msg) {};
void DistanceMetrics::euclideanDistance(const std::vector<double>& vec1, const std::vector<double>& vec2) {
    int counter = 0;
    double sum_of_squares = 0;
    for(double point : vec1) {
        sum_of_squares += std::pow((point - vec2[counter]), 2);
        counter++;
    }
    CkPrintf("Computing distance on processor %d by index %d" CkMyPe(), thisIndex);
    mainProxy.finished(std::sqrt(sum_of_squares), thisIndex);
}

#include "distanceMetrics.def.h"