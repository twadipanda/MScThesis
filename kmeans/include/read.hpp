#pragma once
#include <string>

class Reader {
    private:
        std::string fileName{};
    public:
        Reader(std::string fileName);
        
        void read();
};