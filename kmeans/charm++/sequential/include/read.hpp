/**
 * @file read.hpp
 * @brief Header file for reading and parsing input data for K-Means clustering.
 *
 * Defines the Reader class in the KmeansParser namespace, responsible for reading
 * data points from a file.
 */

 #pragma once
 #include <string>
 #include <vector>
 
 namespace KmeansParser {
     /**
      * @brief Class to read and parse data points from a file.
      */
     class Reader {
         private:
             std::string fileName{};              ///< Name of the input file.
             std::vector<std::vector<double>> all_points{}; ///< Parsed points from the file.
         public:
             /**
              * @brief Constructor for the Reader class.
              * @param fileName Name of the file to read.
              */
             Reader(std::string fileName);
 
             /**
              * @brief Reads and parses the file into a vector of points.
              * @return A vector of vectors, where each inner vector represents a point.
              */
             std::vector<std::vector<double>> readAndParse();
     };
 }