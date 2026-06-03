#pragma once

#include <cstdint>

class Clock {
    uint64_t cycle_ = 0;

public:
    void tick() {
        ++cycle_;
    }

    uint64_t cycle() const {
        return cycle_;
    }

    void reset() {
        cycle_ = 0;
    }
};