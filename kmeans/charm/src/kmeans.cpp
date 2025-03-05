#include <iostream>
#include <vector>
#include <limits.h>
#include "kmeans.decl.h"
#include "kmeans.h"

#include "distanceMetrics.h"
#include "main.decl.h"

extern CProxy_Main mainProxy;
extern /* readonly */ int numElements;

// std::vector<std::pair<int, std::vector<double>>> centerPoints;
std::vector<std::vector<double>> centerPoints;
int counter_;
int size;
int ks;

Kmeans::Kmeans() {};
Kmeans::Kmeans(CkMigrateMessage *msg) {};

std::vector<std::vector<double>> Kmeans::getInitialCenters(const std::vector<std::vector<double>>& points, const int& k) {
    if (k > points.size()) {
        CkPrintf("Error: k (%d) exceeds number of points (%lu)\n", k, points.size());
        CkExit();
    }
    std::vector<std::vector<double>> centers;
    for (int i = 0; i < k; i++) {
        centers.push_back(points[i]);
    }
    return std::move(centers);
}

void Kmeans::computeDistance(const std::vector<std::vector<double>>& points,
    const std::vector<std::vector<double>>& centers) {
        size = points.size();
        ks = centers.size();
        counter_ = 0;
        std::vector<std::vector<double>> distances;
        int pointIndex = 0;
        int pointslength =  points.size();
        int isFinal = 0;
        int chareIndex = 1;
        for (std::vector<double> point : points) {
            if (chareIndex == (numElements - 1)) {
                chareIndex = 1;
            }
            thisProxy[chareIndex].computeDistancePar(centers, point, pointIndex);
            pointIndex++;
            chareIndex++;
        }
}

// void Kmeans::computeDistancePar(const std::vector<std::vector<double>>& centers, const std::vector<double>& point, int pointIndex) {
//     std::vector<double> distance;
//     EuclideanDistance distance_metrics;
//     for (std::vector<double> center: centers) {
//         distance.push_back(distance_metrics.computeDistance(center, point));
//     }
//     mainProxy.finished(distance, pointIndex);
// }

void Kmeans::computeDistancePar(const std::vector<std::vector<double>>& centers, const std::vector<double>& point, int pointIndex) {
    std::vector<double> distance;
    EuclideanDistance distance_metrics;
    for (std::vector<double> center: centers) {
        distance.push_back(distance_metrics.computeDistance(center, point));
    }
    int k = minIndex(distance);
    // centerPoints.push_back(std::make_pair(k, point));
    thisProxy[k].reduce(point);
}

void Kmeans::reduce(const std::vector<double>& point) {
    centerPoints.push_back(point);
    thisProxy[0].received();
}

void Kmeans::received() {
    counter_++;
    if (counter_ == size) {
        for (int i = 0; i < ks; i++) {
            thisProxy[i].done();
        }
    }
}

void Kmeans::done() {
    int size = centerPoints.size();
    if (size > 1) {
        std::vector<double> result;
        result = add(centerPoints[0], centerPoints[1]);
        for (int i = 2; i < size; i++) {
            result = add(result, centerPoints[i]);
        }
        result = div(result, size);
        mainProxy.finished(result, thisIndex);
    }
    else {
        mainProxy.finished(centerPoints[0], thisIndex);
    }
}

int Kmeans::minIndex(const std::vector<double>& distances) {
    int counter = 0;
    int index = 0;
    double min = INT_MAX;
    for (double distance : distances) {
        if (distance < min) {
            min = distance;
            index = counter;
        }
        counter++;
    }
    return index;
}

std::vector<double> Kmeans::add(const std::vector<double>& a, const std::vector<double>& b) {
    int counter = 0;
    std::vector<double> result;
    for (double val : a) {
        result.push_back(val + b[counter]);
        counter++;
    }
    return std::move(result);
}

std::vector<double> Kmeans::div(const std::vector<double>& a, int n) {
    std::vector<double> result;
    for (double val : a) {
        result.push_back(val / n);
    }
    return std::move(result);
}

std::vector<std::vector<double>> Kmeans::computeNewCenters(const std::vector<std::vector<double>>& points,
    const std::vector<std::vector<double>>& distances, int k) {
        std::vector<std::vector<std::vector<double>>> points_for_centers(k);
        int counter = 0;
        for (std::vector<double> distance : distances) {
            points_for_centers[Kmeans::minIndex(distance)].push_back(points[counter]);
            counter++;
        }
        std::vector<std::vector<double>> new_centers;
        std::vector<double> temp_center;
        counter = 0;
        for (std::vector<std::vector<double>> pointss : points_for_centers) {
            for (std::vector<double> point : pointss) {
                if (counter == 0) {
                    temp_center = point;
                }
                else {
                    temp_center = Kmeans::add(temp_center, point);
                }
                counter++;
            }
            temp_center = Kmeans::div(temp_center, counter);
            counter = 0;
            new_centers.push_back(temp_center);
        }
        return std::move(new_centers);
}

#include "kmeans.def.h"