#include <iostream>
using namespace std;
#include <filesystem>
namespace fs = std::filesystem;

#include "decode/regfile/regfile.hpp"
#include "decode/decoder/decodedInst.hpp"
#include "utils/utils.hpp"
#include "decode/decoder/decoder.hpp"
#include "parser/parser.hpp"
#include "fetch/instrMemory.hpp"

#include "fstream"
#include "filesystem"

int main() {
    Regfile rf;
    fs::path dirPath  = "../input/"; // directory path for input files, can be changed as needed
    fs::path filepath = dirPath / "test.txt";
    Parser parser = Parser();
    std::vector<uint32_t> instructions = parser.parseFile(filepath);
    InstrMemory instrMemory(instructions);
    uint32_t instr = instrMemory.fetchInstruction(0);
    utils::printAddress(instr);
    return 0;
}