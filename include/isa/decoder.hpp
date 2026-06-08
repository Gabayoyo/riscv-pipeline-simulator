#pragma once

#include <cstdint>
#include "utils/utils.hpp"
#include "decoderresult.hpp"

class Decoder {
    public:
        Decoder() = default;

        // derives reg1, reg2, src2 (or immediate depending on mux)
        // branch type if applicable
        DecoderResult decodeInstruction(uint32_t rawInstruction);

    private:
        DecoderResult decodeIType(uint32_t raw);
};