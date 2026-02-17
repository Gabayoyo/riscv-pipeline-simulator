#pragma once

#include <cstdint>
#include <vector>

class InstMemory {
    public:
        InstMemory() = default;

        // fetches a 32-bit instruction from the given address
        uint32_t fetchInstruction(uint32_t address);

    private:
        std::vector<uint8_t> memory; // simple vector to represent instruction memory by byte
};