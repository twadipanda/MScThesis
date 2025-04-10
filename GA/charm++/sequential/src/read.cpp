#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "read.hpp"

/**
 * @brief Namespace for K-Means data parsing utilities.
 */
namespace KmeansParser {
  /**
   * @brief Constructs a Reader for a specified file.
   *
   * @param fileName The name of the file to read.
   */
  Reader::Reader(std::string fileName) : fileName{fileName} {};

  /**
   * @brief Reads and parses a file into a vector of point vectors.
   *
   * Assumes the file contains space-separated double values, one line per point.
   *
   * @return std::vector<std::vector<double>> The parsed points.
   */
  std::vector<std::vector<double>> Reader::readAndParse() {
    std::string output;
    std::string point;
    std::vector<double> points;
    std::ifstream reader(fileName);
    while (getline (reader, output)) {
      std::istringstream iss (output);
      while (iss >> point) {
        points.push_back(std::stod(point));
      }
      all_points.push_back(points);
      points.clear();
    }
    reader.close();
    return std::move(all_points);
  }
}