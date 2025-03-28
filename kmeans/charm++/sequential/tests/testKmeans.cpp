#include <gtest/gtest.h>
#include <vector>
#include "kmeans.hpp"

Kmeans::Kmeans kmeans;

TEST(KmeansAdd, AddTwoVectors) {
    EXPECT_EQ(kmeans.add({1, 2}, {3, 4}), std::vector<double>{4, 6});
}

TEST(KmeansAdd, AddThreeVectors) {
    std::vector<double> result = kmeans.add({1, 1}, {2, 2});
    result = kmeans.add(result, {3, 3});
    EXPECT_EQ(result, std::vector<double>{6, 6});
}

TEST(KmeansAdd, SingleVector) {
    EXPECT_EQ(kmeans.add({5, 5}, {0, 0}), std::vector<double>{5, 5});
}

TEST(KmeansAdd, NegativeNumbers) {
    EXPECT_EQ(kmeans.add({-1, 2}, {3, -4}), std::vector<double>{2, -2});
}

TEST(KmeansAdd, FloatingPointNumbers) {
    EXPECT_EQ(kmeans.add({1.5, 2.5}, {2.5, 3.5}), std::vector<double>{4.0, 6.0});
}

TEST(KmeansDiv, VectorScalarDiv) {
    EXPECT_EQ(kmeans.div({4, 6, 8}, 2), std::vector<double>{2, 3, 4});
}

TEST(KmeansDiv, NegativeScalar) {
    EXPECT_EQ(kmeans.div({4, -6, 8}, -2), std::vector<double>{-2, 3, -4});
}

TEST(KmeansDiv, VectorWithZeros) {
    EXPECT_EQ(kmeans.div({0, 0, 0}, 5), std::vector<double>{0, 0, 0});
}

TEST(KmeansDiv, FloatingPointElements) {
    EXPECT_EQ(kmeans.div({1.5, 2.5, 3.5}, 2), std::vector<double>{0.75, 1.25, 1.75});
}

TEST(KmeansDiv, EmptyVector) {
    EXPECT_EQ(kmeans.div({}, 3), std::vector<double>{});
}

TEST(KmeansDiv, DivisionByZero) {
    std::vector<double> result = kmeans.div({1, 2, 3}, 0);
    for (double val : result) {
        EXPECT_TRUE(std::isinf(val));
    }
}

TEST(KmeansComputeNewCenter, SingleClusterAllPoints) {
    std::vector<std::vector<double>> points = {{1, 1}, {3, 3}};
    std::vector<std::vector<double>> initial_centers = {{0, 0}};
    EXPECT_EQ(kmeans.computeNewCenters(points, initial_centers, 1), std::vector<std::vector<double>>{{2, 2}});
}

TEST(KmeansComputeNewCenter, TwoClustersFirstIteration) {
    std::vector<std::vector<double>> points = {{1, 1}, {4, 4}};
    std::vector<std::vector<double>> initial_centers = {{1, 1}, {5, 5}};
    EXPECT_EQ(kmeans.computeNewCenters(points, initial_centers, 2), std::vector<std::vector<double>>{{1, 1}, {4, 4}});
}

TEST(KmeansComputeNewCenter, MultiplePointsPerCluster) {
    std::vector<std::vector<double>> points = {{0, 0}, {1, 1}, {4, 4}, {5, 5}};
    std::vector<std::vector<double>> initial_centers = {{0, 0}, {5, 5}};
    EXPECT_EQ(kmeans.computeNewCenters(points, initial_centers, 2), 
              std::vector<std::vector<double>>{{0.5, 0.5}, {4.5, 4.5}});
}
