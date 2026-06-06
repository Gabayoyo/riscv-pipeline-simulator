#include "pipeline/hazardunit.hpp"

PipelineSignals HazardUnit::detect_load_use(const ID_EX_Reg& id_ex, const IF_ID_Reg& if_id) {
    PipelineSignals pipeSig{};

    // Only a load instruction has mem_read set
    // If the destination of the load matches either source of the next instruction
    if (id_ex.ctrl.mem_read && id_ex.rd != 0) {
        // Decode the incoming instruction's rs1/rs2 from if_id
        uint8_t rs1 = (if_id.instruction >> 15) & 0x1F;
        uint8_t rs2 = (if_id.instruction >> 20) & 0x1F;

        if (id_ex.rd == rs1 || id_ex.rd == rs2) {
            pipeSig.stall_FCH  = true;  // PC holds
            pipeSig.stall_DEC  = true;  // IF/ID holds
            pipeSig.flush_DEC  = true;  // insert bubble into EX
        }
    }

    return pipeSig;
}