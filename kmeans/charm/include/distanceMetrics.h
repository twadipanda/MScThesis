#pragma once
#include <vector>

// class DistanceMetrics : public CBase_DistanceMetrics {
//     public:
//         DistanceMetrics();
//         DistanceMetrics(CkMigrateMessage *msg);
//         double euclideanDistance(const std::vector<double>&, const std::vector<double>&);
// };

class DistanceMetrics {
    public:
        virtual double computeDistance(const std::vector<double>&, const std::vector<double>&) = 0;
};

class EuclideanDistance : public DistanceMetrics {
    public:
        double computeDistance(const std::vector<double>& a, const std::vector<double>& b);
};