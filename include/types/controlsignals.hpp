#pragma once

#include <cstdint>

class ControlSignals {
    public:
        bool RegWrite = false;   // Whether to write to register file
        bool MemRead  = false;   // Whether to read from data memory
        bool MemWrite = false;   // Whether to write to data memory
        bool ALUSrc   = false;   // Whether ALU operand is from imm (true) or reg (false)
        uint8_t ALUOp = 0;       // ALU operation code (e.g. add, sub, etc.)
};