#pragma once
#include <vector>

namespace DM {
    class DistanceMetrics : public CBase_DistanceMetrics {
        public:
            DistanceMetrics();
            DistanceMetrics(CkMigrateMessage *msg);
            void euclideanDistance(const std::vector<double>&, const std::vector<double>&);
    };
}