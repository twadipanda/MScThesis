#include <gtest/gtest.h>
#include <vector>
#include <cmath>
#include "kmeans.hpp"

Kmeans::Kmeans kmeans;

TEST(KmeansAdd, AddTwoVectors) {
    std::vector<double> expected = {4, 6};
    EXPECT_EQ(kmeans.add({1, 2}, {3, 4}), expected);
}

TEST(KmeansAdd, AddThreeVectors) {
    std::vector<double> result = kmeans.add({1, 1}, {2, 2});
    result = kmeans.add(result, {3, 3});
    std::vector<double> expected = {6, 6};
    EXPECT_EQ(result, expected);
}

TEST(KmeansAdd, SingleVector) {
    std::vector<double> expected = {5, 5};
    EXPECT_EQ(kmeans.add({5, 5}, {0, 0}), expected);
}

TEST(KmeansAdd, NegativeNumbers) {
    std::vector<double> expected = {2, -2};
    EXPECT_EQ(kmeans.add({-1, 2}, {3, -4}), expected);
}

TEST(KmeansAdd, FloatingPointNumbers) {
    std::vector<double> expected = {4.0, 6.0};
    EXPECT_EQ(kmeans.add({1.5, 2.5}, {2.5, 3.5}), expected);
}

TEST(KmeansDiv, VectorScalarDiv) {
    std::vector<double> expected = {2, 3, 4};
    EXPECT_EQ(kmeans.div({4, 6, 8}, 2), expected);
}

TEST(KmeansDiv, NegativeScalar) {
    std::vector<double> expected = {-2, 3, -4};
    EXPECT_EQ(kmeans.div({4, -6, 8}, -2), expected);
}

TEST(KmeansDiv, VectorWithZeros) {
    std::vector<double> expected = {0, 0, 0};
    EXPECT_EQ(kmeans.div({0, 0, 0}, 5), expected);
}

TEST(KmeansDiv, FloatingPointElements) {
    std::vector<double> expected = {0.75, 1.25, 1.75};
    EXPECT_EQ(kmeans.div({1.5, 2.5, 3.5}, 2), expected);
}

TEST(KmeansDiv, EmptyVector) {
    std::vector<double> expected = {};
    EXPECT_EQ(kmeans.div({}, 3), expected);
}

TEST(KmeansDiv, DivisionByZero) {
    std::vector<double> result = kmeans.div({1, 2, 3}, 0);
    for (double val : result) {
        EXPECT_TRUE(std::isinf(val));
    }
}

TEST(KmeansComputeNewCenter, SingleClusterAllPoints) {
    std::vector<std::vector<double>> points = {{1, 1}, {3, 3}};
    std::vector<std::vector<double>> distances = {{0}, {1}};
    std::vector<std::vector<double>> expected = {{2, 2}};
    EXPECT_EQ(kmeans.computeNewCenters(points, distances, 1), expected);
}

TEST(KmeansComputeNewCenter, TwoClustersFirstIteration) {
    std::vector<std::vector<double>> points = {{1, 1}, {4, 4}};
    std::vector<std::vector<double>> distances = {{0, 1}, {1, 0}};
    std::vector<std::vector<double>> expected = {{1, 1}, {4, 4}};
    EXPECT_EQ(kmeans.computeNewCenters(points, distances, 2), expected);
}

TEST(KmeansComputeNewCenter, MultiplePointsPerCluster) {
    std::vector<std::vector<double>> points = {{0, 0}, {1, 1}, {4, 4}, {5, 5}};
    std::vector<std::vector<double>> distances = {{0, 1}, {0, 1}, {1, 0}, {1, 0}};
    std::vector<std::vector<double>> expected = {{0.5, 0.5}, {4.5, 4.5}};
    EXPECT_EQ(kmeans.computeNewCenters(points, distances, 2), expected);
}
