#pragma once

#include <string>

enum class InstructionType {
    R_TYPE,
    I_TYPE,
    S_TYPE,
    B_TYPE,
    U_TYPE,
    J_TYPE
};

class RISCop {
    protected:
        InstructionType instrType;
        virtual void parse(const std::string& inputString) = 0;
    
    public:
        std::string opString;
        uint8_t rd;
        uint8_t rs1;
        uint8_t rs2;
        uint8_t opcode;
        int32_t immediate;
        uint32_t offset;
        uint8_t funct3;
        uint8_t funct7;


        RISCop(std::string inputString);
        virtual ~RISCop() = default;

        InstructionType getType() const { return instrType; }
};

class IType : public RISCop {
    protected:
        void parse(const std::string& inputString) override;
    public:
        IType(std::string inputString);
};

