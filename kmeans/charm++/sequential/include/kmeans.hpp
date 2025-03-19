#pragma once
#include <vector>
#include "distanceMetrics.hpp"

namespace Kmeans {
    class Kmeans {
        public:
            std::vector<std::vector<double>> getInitialCenters(const std::vector<std::vector<double>>&, const int&);
            std::vector<std::vector<double>> computeDistance(const std::vector<std::vector<double>>&,
                const std::vector<std::vector<double>>&, double (DM::DistanceMetrics::*func)(const std::vector<double>&, const std::vector<double>&),
                DM::DistanceMetrics&);
            int minIndex(const std::vector<double>&);
            std::vector<std::vector<double>> computeNewCenters(const std::vector<std::vector<double>>&, const std::vector<std::vector<double>>&, int);
            std::vector<double> add(const std::vector<double>&, const std::vector<double>&);
            std::vector<double> div(const std::vector<double>&, int);
    };
}