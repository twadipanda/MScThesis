#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "read.h"

namespace KmeansParser {
    Reader::Reader(std::string fileName) : fileName{fileName} {};

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