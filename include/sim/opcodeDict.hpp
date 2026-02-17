#pragma once

#include <map>
#include <string>
using namespace std;

struct InstrEncoding {
    uint8_t opcode;
    uint8_t funct3;
    uint8_t funct7;
};

// RISC string to opcode/funct3/funct7 mapping
map<string, InstrEncoding> opcodeDict = {
    // R-type
    {"ADD", {0b0110011, 0x0, 0x00}},
    {"SUB", {0b0110011, 0x0, 0x20}},
    {"AND", {0b0110011, 0x7, 0x00}},
    {"OR",  {0b0110011, 0x6, 0x00}},
    {"XOR", {0b0110011, 0x4, 0x00}},
    {"SRA", {0b0110011, 0x5, 0x20}},
    {"SLL", {0b0010011, 0x1, 0x00}},
    {"SRL", {0b0010011, 0x5, 0x00}},
    {"SLT", {0b0110011, 0x2, 0x00}},
    {"SLTU",{0b0110011, 0x3, 0x00}},
    // I-type
    {"ADDI", {0b0010011, 0x0, 0x00}},
    {"XORI", {0b0010011, 0x4, 0x00}},
    {"ORI",  {0b0010011, 0x6, 0x00}},
    {"ANDI", {0b0010011, 0x7, 0x00}},
    {"SLLI", {0b0010011, 0x1, 0x00}},
    {"SRLI", {0b0010011, 0x5, 0x00}},
    {"SRAI", {0b0010011, 0x5, 0x00}}, // funct7 actually 0x20 but will be encoded with the immediate
};