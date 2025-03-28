#include <gtest/gtest.h>
 #include <vector>
#include "distanceMetrics.hpp"

DM::DistanceMetrics dm;

// Test cases
TEST(DistanceMetricsEuclideanDistance, TwoDVector) {
    EXPECT_EQ(dm.euclideanDistance({1,2}, {4,6}), 5);
}
