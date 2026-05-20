#pragma once

#include <cstdint>
#include "utils/utils.hpp"
#include "decodedInst.hpp"

class Decoder {
    public:
        Decoder() = default;

        // decodes a 32-bit raw instruction into a DecodedInst object
        // sends values to appropriate locations in decode stage
        DecodedInst decodeInstruction(uint32_t rawInstruction);

};