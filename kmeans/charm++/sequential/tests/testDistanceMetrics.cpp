#include <gtest/gtest.h>
#include <vector>
#include "distanceMetrics.hpp"

DM::DistanceMetrics dm;
// Test cases

TEST(DistanceMetricsEuclideanDistance, TwoDVector) {
    EXPECT_EQ(dm.euclideanDistance({1,2}, {4,6}), 5);
}

TEST(DistanceMetricsEuclideanDistance, ThreeDVector) {
    EXPECT_EQ(dm.euclideanDistance({0, 0, 0}, {3, 4, 0}), 5);
}

TEST(DistanceMetricsEuclideanDistance, TwoDVectorNegative) {
    EXPECT_EQ(dm.euclideanDistance({-1, 3}, {2, -1}), 5);
}

TEST(DistanceMetricsEuclideanDistance, FourDVector) {
    EXPECT_EQ(dm.euclideanDistance({1, 2, 3, 4}, {5, 6, 7, 8}), 8);
}

TEST(DistanceMetricsEuclideanDistance, TwoDVectorSamePoints) {
    EXPECT_EQ(dm.euclideanDistance({2, 3}, {2, 3}), 0);
}

TEST(DistanceMetricsEuclideanDistance, TwoDVectorFloatPoints) {
    EXPECT_EQ(dm.euclideanDistance({1.5, 2.5}, {4.5, 6.5}), 5);
}
