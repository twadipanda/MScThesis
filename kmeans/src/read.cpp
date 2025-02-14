#include <iostream>
#include <string>
#include <fstream>

#include "read.hpp"

Reader::Reader(std::string fileName) : fileName{fileName} {};

void Reader::read() {
    std::string output;
    std::ifstream reader(fileName);
    std::cout << fileName;
    while (getline (reader, output)) {
        std::cout << output;
    }
    reader.close();
};