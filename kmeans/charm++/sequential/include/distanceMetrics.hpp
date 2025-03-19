#pragma once
#include <vector>

namespace DM {
    class DistanceMetrics {
        public:
            double euclideanDistance(const std::vector<double>&, const std::vector<double>&);
    };
}