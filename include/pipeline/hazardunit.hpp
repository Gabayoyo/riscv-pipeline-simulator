#pragma once

#include <cstdint>
#include <iterator>

#include "pipeline/pipereg.hpp"
#include "pipelinesignals.hpp"

class ID_EX_Reg;
class IF_ID_Reg;

class HazardUnit {
    public:

        // Called every tick during combinational logic phase
        // to detect hazards and generate appropriate pipeline control signals
        // We use const to signal: args are read-only and should not be modified by this function
        PipelineSignals detect_load_use(const ID_EX_Reg& id_ex, const IF_ID_Reg& if_id);
};