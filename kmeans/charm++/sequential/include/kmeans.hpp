/**
 * @file kmeans.hpp
 * @brief Header file for the K-Means clustering algorithm implementation.
 *
 * Defines the Kmeans class in the Kmeans namespace, providing methods for clustering.
 */

 #pragma once
 #include <vector>
 #include "distanceMetrics.hpp"
 
 namespace Kmeans {
     /**
      * @brief Class implementing the K-Means clustering algorithm.
      */
     class Kmeans {
         public:
             /**
              * @brief Selects initial cluster centers from the data points.
              * @param points List of all data points.
              * @param k Number of clusters.
              * @return Initial centers as a vector of vectors.
              */
             std::vector<std::vector<double>> getInitialCenters(const std::vector<std::vector<double>>& points, const int& k);
 
             /**
              * @brief Computes distances between points and centers using a specified metric.
              * @param points List of data points.
              * @param centers Current cluster centers.
              * @param func Pointer to the distance metric function.
              * @param obj Reference to the DistanceMetrics object.
              * @return A vector of distance vectors, one per point.
              */
             std::vector<std::vector<double>> computeDistance(const std::vector<std::vector<double>>& points,
                 const std::vector<std::vector<double>>& centers, 
                 double (DM::DistanceMetrics::*func)(const std::vector<double>&, const std::vector<double>&),
                 DM::DistanceMetrics& obj);
 
             /**
              * @brief Finds the index of the minimum value in a distance vector.
              * @param distances Vector of distances.
              * @return Index of the minimum distance.
              */
             int minIndex(const std::vector<double>& distances);
 
             /**
              * @brief Computes new cluster centers based on point assignments.
              * @param points List of data points.
              * @param distances Distances from points to centers.
              * @param k Number of clusters.
              * @return Updated cluster centers.
              */
             std::vector<std::vector<double>> computeNewCenters(const std::vector<std::vector<double>>& points, 
                 const std::vector<std::vector<double>>& distances, int k);
 
             /**
              * @brief Adds two vectors element-wise.
              * @param a First vector.
              * @param b Second vector.
              * @return Resulting vector from the addition.
              */
             std::vector<double> add(const std::vector<double>& a, const std::vector<double>& b);
 
             /**
              * @brief Divides a vector by a scalar.
              * @param a Vector to divide.
              * @param n Scalar denominator.
              * @return Resulting vector after division.
              */
             std::vector<double> div(const std::vector<double>& a, int n);
     };
 }