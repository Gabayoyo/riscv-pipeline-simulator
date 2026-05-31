#include "memory/iccm.hpp"
#include <iostream>
using namespace std;

ICCM::ICCM(std::vector<uint32_t> instructions) {
    // Convert vector of 32-bit instructions to byte vector
    for (uint32_t inst : instructions) {
        memory.push_back(static_cast<uint8_t>(inst & 0xFF));
        memory.push_back(static_cast<uint8_t>((inst >> 8) & 0xFF));
        memory.push_back(static_cast<uint8_t>((inst >> 16) & 0xFF));
        memory.push_back(static_cast<uint8_t>((inst >> 24) & 0xFF));
    }
}

// we use const for two functions below as they do not modify the state of the instruction memory object
uint32_t ICCM::fetchInstruction(uint32_t address) const {
    if (address + 3 >= memory.size()) {
        throw std::out_of_range("Address out of bounds for instruction memory");
    }
    // Fetch 4 bytes and combine into a 32-bit instruction
    uint32_t inst = 0;
    inst |= static_cast<uint32_t>(memory[address]);
    inst |= static_cast<uint32_t>(memory[address + 1]) << 8;
    inst |= static_cast<uint32_t>(memory[address + 2]) << 16;
    inst |= static_cast<uint32_t>(memory[address + 3]) << 24;
    return inst;
}

void ICCM::printInstructions(uint32_t offset) const {
    for (size_t i = offset; i < memory.size(); i += 4) {
        uint32_t inst = fetchInstruction(i);
        cout << "0x" << hex << (i) << ": 0x" << hex << inst << endl;
    }
}