#pragma once

#include <cstdint>

struct PipelineSignals {
    bool stall_FCH = false;
    bool stall_DEC = false;

    bool flush_FCH = false;
    bool flush_DEC = false;

    bool branch_taken = false;
    uint32_t branch_target = 0;

    void merge(const PipelineSignals& other);
};

