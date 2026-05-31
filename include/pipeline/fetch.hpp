#pragma once

#include "pipeline/stage.hpp"
#include "piperegisters.hpp"
#include "memory/iccm.hpp"

// forward declarations to avoid circular dependencies
// and prevents unnecessary includes in the header file
class ICCM;
struct ID_EX_Reg;
struct EX_MEM_Reg;

class Fetch : public Stage {
    ID_EX_Reg&  in;
    EX_MEM_Reg& out;
    ICCM&       iccm;

    public:
        Fetch(ID_EX_Reg& in, EX_MEM_Reg& out, ICCM& iccm) : in(in), out(out), iccm(iccm) {}

        void execute() override;
};