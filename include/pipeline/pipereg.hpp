#pragma once

#include <cstdint>

#include "types/controlsignals.hpp"

struct IF_ID_Reg {
    uint32_t dec_pc = 0;
    uint32_t instruction;
};

struct ID_EX_Reg {
    uint32_t exe_pc = 0;
    uint32_t exe_reg1, exe_reg2, exe_src2;
    bool valid = false;
    ControlSignals ctrl;
};

struct EX_MEM_Reg {
    uint32_t mem_pc = 0;
    uint32_t alu_result;
    uint32_t rs2_val;         // for stores
    uint8_t  rd;
    bool valid = false;
    ControlSignals ctrl;
};

struct MEM_WB_Reg {
    uint32_t nxt_pc = 0;
    uint32_t alu_result;
    uint32_t mem_data;
    uint8_t  rd;
    bool valid = false;
    ControlSignals ctrl;
};