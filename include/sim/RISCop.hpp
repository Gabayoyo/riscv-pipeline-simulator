#pragma once

#include <string>
using namespace std;

class RISCop {
    public:
        string opString;
        uint8_t rd;
        uint8_t rs1;
        uint8_t rs2;
        uint8_t opcode;
        int32_t immediate;
        uint32_t offset;
        uint8_t funct3;
        uint8_t funct7;


        RISCop(string inputOp);
};

