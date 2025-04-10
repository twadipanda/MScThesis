
#pragma once

#include <string>
#include <vector>

namespace KmeansParser {
  class Reader {
    private:
      std::string fileName{};
      std::vector<std::vector<double>> all_points{};
    public:
      Reader(std::string fileName);
      std::vector<std::vector<double>> readAndParse();
    };
}