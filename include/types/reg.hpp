#pragma once

#include <cstdint>

class Reg {
    public:
        Reg() = default;
        Reg(uint32_t value) : value(value) {}

        uint32_t getValue() const {
            return value;
        }

        void setValue(uint32_t newValue) {
            value = newValue;
        }

    private:
        uint32_t value{0};
};