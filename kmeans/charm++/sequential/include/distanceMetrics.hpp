/**
 * @file distanceMetrics.hpp
 * @brief Header file for distance metric calculations.
 *
 * Defines the DistanceMetrics class in the DM namespace, providing methods for
 * distance computation.
 */

 #pragma once
 #include <vector>
 
 namespace DM {
     /**
      * @brief Class providing distance metric functions.
      */
     class DistanceMetrics {
         public:
             /**
              * @brief Computes the Euclidean distance between two vectors.
              * @param vec1 First vector.
              * @param vec2 Second vector.
              * @return Euclidean distance between the vectors.
              */
             double euclideanDistance(const std::vector<double>& vec1, const std::vector<double>& vec2);
     };
 }