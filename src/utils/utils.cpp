#include "utils/utils.hpp"

#include <cstdint>
#include <iostream>
#include <iomanip>

namespace utils {  
    void printAddress(uint32_t address) {
        std::cout << "0x" << std::hex << std::setfill('0') << std::setw(8) << address << std::dec << "\n";
    }
}