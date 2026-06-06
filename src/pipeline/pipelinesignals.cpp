#include <pipeline/pipelinesignals.hpp>

void PipelineSignals::merge(const PipelineSignals& other) {
    stall_FCH |= other.stall_FCH;
    stall_DEC |= other.stall_DEC;
    flush_FCH |= other.flush_FCH;
    flush_DEC |= other.flush_DEC;
    branch_taken |= other.branch_taken;
    if (other.branch_taken) {
        branch_target = other.branch_target;
    }
}