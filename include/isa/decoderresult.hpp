#pragma once

#include "utils/utils.hpp"

// base class for decoded RISC-V instructions
// probably will remove soon
class DecoderResult {
    public:
        virtual ~DecoderResult() = default;
        
        unsigned int opcode : 7;
        unsigned int rs1 : 5;
        unsigned int rs2 : 5;
        unsigned int rd : 5;
        unsigned int funct3 : 3;
        unsigned int funct7 : 7;
        signed int imm : 20;
};