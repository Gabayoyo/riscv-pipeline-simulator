#include <iostream>
using namespace std;

#include "decode/regfile/regfile.hpp"
#include "decode/decoder/decodedInst.hpp"
#include "sim/RISCop.hpp"
#include "sim/instTranslator.hpp"
#include "sim/instConstructor.hpp"
#include "utils/utils.hpp"
#include "decode/decoder/decoder.hpp"

#include "fstream"
#include "filesystem"

int main() {

    Regfile rf;

    fs::path dirPath  = "../input/"; // directory path for input files, can be changed as needed
    fs::path filepath = dirPath / "test.txt";
    instConstructor constructor;
    InstMemory instMem = constructor.constructInstMemoryFromFile(filepath); // construct instruction memory from
    uint32_t inst = instMem.fetchInstruction(0x0); // fetch instruction at address 0
    uint32_t inst2 = instMem.fetchInstruction(0x4); // fetch instruction at address 4
    std::bitset<32> instBits(inst);
    std::bitset<32> inst2Bits(inst2);
    cout << "Fetched instruction: " << instBits << endl;
    cout << "Fetched instruction: " << inst2Bits << endl;
    return 0;
}