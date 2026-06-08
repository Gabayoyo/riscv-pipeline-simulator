#pragma once

#include <cstdint>

class ControlSignals {
    public:
        bool reg_write = false; // Whether to write to register file
        bool mem_read  = false; // Whether to read from data memory
        bool mem_write = false; // Whether to write to data memory
        bool alu_src   = false; // Whether ALU operand is from imm (true) or reg (false)
        int branch_type = 0; // may change later
        uint8_t alu_op = 0; // ALU operation code (e.g. add, sub, etc.)
};