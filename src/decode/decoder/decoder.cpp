#include "decode/decoder/decoder.hpp"
#include <iostream>
#include <bitset>
using namespace std;

DecodedInst Decoder::decodeInstruction(uint32_t rawInstruction) {
    uint8_t opcode = utils::selectBits(rawInstruction, 0, 7);
    switch (opcode) {
        case 0b0110011: { // R-type instruction
            DecodedInstR decodedR(rawInstruction);
            return decodedR;
        }
        case 0b0010011: { // I-type instruction
            DecodedInstI decodedI(rawInstruction);
            return decodedI;
        }
        default:
            throw runtime_error("Unsupported opcode: " + to_string(opcode));
    }
}