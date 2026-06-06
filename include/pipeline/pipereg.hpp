#pragma once

#include <cstdint>

#include "../types/controlsignals.hpp"

struct IF_ID_Reg {
    uint32_t instruction;
    uint32_t pc = 0;
};

struct ID_EX_Reg {
    uint32_t pc = 0;
    uint32_t rs1_val, rs2_val;
    uint32_t imm;
    uint8_t  rd;
    ControlSignals ctrl;
};

struct EX_MEM_Reg {
    uint32_t alu_result;
    uint32_t rs2_val;         // for stores
    uint8_t  rd;
    ControlSignals ctrl;
};

struct MEM_WB_Reg {
    uint32_t alu_result;
    uint32_t mem_data;
    uint8_t  rd;
    ControlSignals ctrl;
};