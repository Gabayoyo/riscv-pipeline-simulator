#pragma once

#include <cstdint>

struct PipelineSignals {
    bool stall_if = false;
    bool stall_id = false;

    bool flush_if = false;
    bool flush_id = false;

    bool branch_taken = false;
    uint32_t branch_target = 0;

    void merge(const PipelineSignals& other);
};

