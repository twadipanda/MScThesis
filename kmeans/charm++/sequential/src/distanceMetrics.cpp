#include <cmath>
#include <vector>
#include "distanceMetrics.hpp"

namespace DM {
    double DistanceMetrics::euclideanDistance(const std::vector<double>& vec1, const std::vector<double>& vec2) {
        int counter = 0;
        double sum_of_squares = 0;
        for(double point : vec1) {
            sum_of_squares += std::pow((point - vec2[counter]), 2);
            counter++;
        }
        return std::sqrt(sum_of_squares);
    }
}