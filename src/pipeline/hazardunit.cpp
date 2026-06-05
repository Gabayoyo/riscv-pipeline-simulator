#include "pipeline/hazardunit.hpp"

HazardSignals HazardUnit::detect_load_use(const ID_EX_Reg& id_ex,
                                 uint8_t rs1, uint8_t rs2) {
    HazardSignals signals;
    signals.stall_if = false;
    signals.stall_id = false;

    if (!id_ex.valid)          return signals;
    if (!id_ex.ctrl.MemRead)  return signals;  // only loads cause this hazard
    if (id_ex.rd == 0)         return signals;  // x0 writes are discarded. TODO: can enforce elsewhere

    if (id_ex.rd == rs1 || id_ex.rd == rs2) {
        // Must stall — the value won't be available until MEM next cycle
        signals.stall_if = true;
        signals.stall_id = true;        // bubble gets inserted into id_ex
    }
    return signals;
}