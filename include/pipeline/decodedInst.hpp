#pragma once

#include <cstdint>
#include "utils/utils.hpp"

// base class for decoded RISC-V instructions
class DecodedInst {
    public:
        virtual ~DecodedInst() = default;
        uint32_t opcode;

    protected:
        // automatically extract opcode from raw bits
        DecodedInst(uint32_t bits) {
            opcode = utils::selectBits(bits, 0, 7);
        }
};

class DecodedInstR : public DecodedInst {
    public:
        uint8_t rd;
        uint8_t funct3;
        uint8_t rs1;
        uint8_t rs2;
        uint8_t funct7;

        DecodedInstR(uint32_t raw) : DecodedInst(raw) {
            rd = utils::selectBits(raw, 7, 5);
            funct3 = utils::selectBits(raw, 12, 3);
            rs1 = utils::selectBits(raw, 15, 5);
            rs2 = utils::selectBits(raw, 20, 5);
            funct7 = utils::selectBits(raw, 25, 7);
        }
};

class DecodedInstI : public DecodedInst {
    public:
        uint8_t rd;
        uint8_t funct3;
        uint8_t rs1;
        int32_t immediate;

        DecodedInstI(uint32_t raw) : DecodedInst(raw) {
            rd = utils::selectBits(raw, 7, 5);
            funct3 = utils::selectBits(raw, 12, 3);
            rs1 = utils::selectBits(raw, 15, 5);
            immediate = static_cast<int32_t>(utils::selectBits(raw, 20, 12));
            // sign-extend immediate if necessary
            if (immediate & (1u << 11)) {
                immediate |= 0xFFFFF000; // set upper 20 bits to 1
            }
        }
};