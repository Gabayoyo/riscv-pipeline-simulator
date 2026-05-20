#pragma once

#include <cstdint>
#include <vector>

class ICCM {
    public:
        // constructor that takes a vector of 32-bit instructions and converts to byte vector for memory representation
        ICCM(std::vector<uint32_t> instructions);

        // fetches a 32-bit instruction from the given address
        uint32_t fetchInstruction(uint32_t address) const;

        // purely for debugging
        void printInstructions(uint32_t offset) const;

    private:
        // simple vector to represent instruction memory by byte
        // important for accurate memory representation and fetching of instructions in the correct format
        std::vector<uint8_t> memory;
};