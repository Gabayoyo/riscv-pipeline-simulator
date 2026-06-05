#pragma once

#include <cstdint>
#include <iterator>

#include "pipeline/pipereg.hpp"
#include "pipeline/pipelinecontrol.hpp"

class ID_EX_Reg;

class HazardUnit {
    public:

        // Called every tick by stage_ID — detects load-use hazard
        // A load in EX targeting a register that ID needs right now
        PipelineSignals detect_load_use(const ID_EX_Reg& id_ex,
                            uint8_t rs1, uint8_t rs2);
};