#pragma once

#include <cstdint>
#include <functional>
#include <vector>

// Subscriber model for functions to be called on each clock tick
// e.g. clock.subscribe([&]() { pipeline.tick(); });
class Clock {
    uint64_t cycle_ = 0;
    std::vector<std::function<void()>> subscribers_;

public:
    void subscribe(std::function<void()> fn) {
        subscribers_.push_back(fn);
    }

    void tick() {
        cycle_++;
        for (auto& fn : subscribers_)
            fn();
    }

    void run(uint64_t cycles) {
        for (uint64_t i = 0; i < cycles; i++)
            tick();
    }

    uint64_t cycle() const { return cycle_; }
};