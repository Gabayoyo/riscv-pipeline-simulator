#pragma once

#include "sim/clock.hpp"
#include "core/cpu.hpp"

class Simulator {
    Clock clock;
    CPU cpu;

    public:
        Simulator(CPU& cpu, Clock& clock) : cpu(cpu), clock(clock) {}

        void run(uint64_t max_cycles) {
            while (!cpu.halted() && clock.cycle() < max_cycles) {
                tick();
            }
        }

        void tick() {
            cpu.tick();
            clock.tick();
        }
};