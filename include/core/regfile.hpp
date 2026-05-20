#pragma once

#include <array>

// Register File
class Regfile {
    public:

        // register read function
        uint32_t read(uint16_t addr) const;

        // register write function
        // register 0 is hardwired to 0 and cannot be written to
        void write(uint16_t addr, uint32_t data);

        // printing functions for debugging
        void printAll() const;
        void printReg(uint16_t addr) const;

    private:
        std::array<uint32_t, 32> regs{};
};