#include "sim/instConstructor.hpp"
#include <fstream>
#include <iostream>
#include "sim/RISCop.hpp"
#include "sim/instTranslator.hpp"

InstMemory instConstructor::constructInstMemoryFromFile(fs::path filepath) {

    if (!fs::exists(filepath)) {
        throw std::invalid_argument("File does not exist: " + filepath.string());
    }

    if (!fs::is_regular_file(filepath)) {
        throw std::invalid_argument("File is not a regular file: " + filepath.string());
    }

    std::ifstream file(filepath);
    if (!file.is_open()) {
        throw std::invalid_argument("Failed to open file: " + filepath.string());
    }

    InstTranslator translator;
    std::vector<uint32_t> instructions;

    // read each line until EOF
    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        // construct RISCop object from line and translate to 32-bit instruction, adding to vector of instructions
        // const RISCop& op(line);
        // uint32_t inst32 = translator.instTo32Bit(op);
        //instructions.push_back(inst32);
    }

    // construct instruction memory from vector of instructions
    InstMemory instMem(instructions);
    return instMem;
}