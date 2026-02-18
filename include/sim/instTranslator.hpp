#pragma once

#include "RISCop.hpp"

// Class that translates the high-level RISCop class into a 32-bit instruction format.
class InstTranslator {
    public:
        InstTranslator() = default;

        // translates a RISCop object into a 32-bit value
        uint32_t instTo32Bit(const RISCop& op);
};