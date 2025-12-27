#pragma once

#include "RISCop.hpp"

class InstTranslator {
    public:
        InstTranslator() = default;

        // translates a RISCop object into a 32-bit value
        uint32_t instTo32Bit(RISCop op);
};