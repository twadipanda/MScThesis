#include <vector>
#include <limits.h>
#include "kmeans.h"
#include "kmeans.decl.h"

#include "distanceMetrics.h"
#include "main.decl.h"
// #include "distanceMetrics.decl.h"

extern CProxy_Main mainProxy;
extern /* readonly */ int numElements;

Kmeans::Kmeans() {};
Kmeans::Kmeans(CkMigrateMessage *msg) {};

std::vector<std::vector<double>> Kmeans::getInitialCenters(const std::vector<std::vector<double>>& points, const int& k) {
    std::vector<std::vector<double>> centers;
    for (int i = 0; i < k; i++) {
        centers.push_back(points[i]);
    }
    return std::move(centers);
}

void Kmeans::computeDistance(const std::vector<std::vector<double>>& points,
    const std::vector<std::vector<double>>& centers) {
        std::vector<std::vector<double>> distances;
        int pointIndex = 0;
        int pointslength =  points.size()
        int isFinal = 0;
        for (std::vector<double> point : points) {
            if (pointIndex + 1 == pointslength) {
                isFinal = 1;
            }
            if (thisIndex < (numElements - 1)) {
                thisProxy[thisIndex + 1].computeDistancePar(centers, point, obj, pointIndex, isFinal);
                pointIndex++;
            }
            else {
                thisProxy[thisIndex].computeDistancePar(centers, point, obj, pointIndex, isFinal);
                pointIndex++;
                // distances.push_back(distance);
                // distance.clear();
            }
        }
        // return std::move(distances);
}

void Kmeans::computeDistancePar(const std::vector<std::vector<double>>& centers, const std::vector<double>& point, int pointIndex, int isFinal) {
    std::vector<double> distance;
    CkPrintf("Computing distance on processor %d by index %d\n", CkMyPe(), thisIndex);
    for (std::vector<double> center: centers) {
        distance.push_back(EuclideanDistance().computeDistance(center, point));
    }
    mainProxy.finished(distance, pointIndex, isFinal);
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