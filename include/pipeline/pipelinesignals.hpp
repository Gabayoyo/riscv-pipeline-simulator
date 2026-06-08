#pragma once

#include <cstdint>

struct PipelineSignals {
    bool stall_FCH = false;
    bool stall_DEC = false;

    bool flush_FCH = false;
    bool flush_DEC = false;

    bool branch_taken = false;
    uint32_t branch_target = 0;

    // exe forwarding
    uint32_t exe_result = 0;
    unsigned int exe_dest : 5;
    bool exe_reg_write = false;

    // mem forwarding
    uint32_t mem_result = 0;
    unsigned int mem_dest : 5;
    bool mem_reg_write = false;

    // wrb forwarding
    uint32_t wrb_result = 0;
    unsigned int wrb_dest : 5;
    bool wrb_reg_write = false;

    void merge(const PipelineSignals& other);
};

