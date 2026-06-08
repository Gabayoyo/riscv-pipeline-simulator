#include <string>
#include <set>

#include "isa/decoder.hpp"
#include <iostream>

DecoderResult Decoder::decodeInstruction(uint32_t rawInstruction) {
    uint8_t opcode = rawInstruction & 0x7F;

    switch (opcode) {
        case 0b0010011:
            return decodeIType(rawInstruction);
        default:
            throw std::runtime_error("Unsupported opcode: " + std::to_string(opcode));
    }
}

DecoderResult Decoder::decodeIType(uint32_t raw) {
    DecoderResult result{};
    result.rd = utils::selectBits(raw, 7, 5);
    result.funct3 = utils::selectBits(raw, 12, 3);
    result.rs1 = utils::selectBits(raw, 15, 5);
    result.imm = static_cast<int32_t>(utils::selectBits(raw, 20, 12));
    // sign-extend immediate if necessary
    if (result.imm & (1u << 11)) {
        result.imm |= 0xFFFFF000; // set upper 20 bits to 1
    }
    return result;
}