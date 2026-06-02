#include <iostream>
using namespace std;
#include <filesystem>
namespace fs = std::filesystem;

#include "core/regfile.hpp"
#include "utils/utils.hpp"
#include "isa/decoder.hpp"
#include "asm/parser.hpp"
#include "memory/iccm.hpp"
#include "core/cpu.hpp"

#include "fstream"
#include "filesystem"

int main() {
    fs::path dirPath  = "../input/"; // directory path for input files, can be changed as needed
    fs::path filepath = dirPath / "test.txt";

    Parser parser = Parser();
    std::vector<uint32_t> instructions = parser.parseFile(filepath);
    ICCM instrMemory(instructions);
    Regfile rf;
    BPU bpu;

    CPU cpu(instrMemory, rf, bpu);

    Clock clk;
    cpu.connect(clk);
    clk.run(10);

    return 0;
}