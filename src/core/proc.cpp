#include <iostream>
using namespace std;
#include <filesystem>
namespace fs = std::filesystem;

#include "core/regfile.hpp"
#include "core/pipeline/decode/decoder.hpp"
#include "utils/utils.hpp"
#include "core/pipeline/decode/decoder.hpp"
#include "asm/parser.hpp"
#include "core/pipeline/fetch/iccm.hpp"

#include "fstream"
#include "filesystem"

int main() {
    Regfile rf;
    fs::path dirPath  = "../input/"; // directory path for input files, can be changed as needed
    fs::path filepath = dirPath / "test.txt";
    Parser parser = Parser();
    std::vector<uint32_t> instructions = parser.parseFile(filepath);
    ICCM instrMemory(instructions);
    instrMemory.printInstructions(0);
    return 0;
}