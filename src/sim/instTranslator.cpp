#include "sim/instTranslator.hpp"
#include "utils/utils.hpp"

uint32_t InstTranslator::instTo32Bit(const RISCop& op) {
    uint32_t instruction = 0;

    switch (op.opcode) {
        case 0b0110011: // R-type instruction
            // Set opcode (bits 0-6)
            instruction = utils::setBitsInRange(instruction, op.opcode, 0, 7);
            // Set rd (bits 7-11)
            instruction = utils::setBitsInRange(instruction, op.rd, 7, 5);
            // Set funct3 (bits 12-14)
            instruction = utils::setBitsInRange(instruction, op.funct3, 12, 3);
            // Set rs1 (bits 15-19)
            instruction = utils::setBitsInRange(instruction, op.rs1, 15, 5);
            // Set rs2 (bits 20-24)
            instruction = utils::setBitsInRange(instruction, op.rs2, 20, 5);
            // Set funct7 (bits 25-31)
            instruction = utils::setBitsInRange(instruction, op.funct7, 25, 7);
            return instruction;
        case 0b0010011: // I-type instruction
            // Set opcode (bits 0-6)
            instruction = utils::setBitsInRange(instruction, op.opcode, 0, 7);
            // Set rd (bits 7-11)
            instruction = utils::setBitsInRange(instruction, op.rd, 7, 5);
            // Set funct3 (bits 12-14)
            instruction = utils::setBitsInRange(instruction, op.funct3, 12, 3);
            // Set rs1 (bits 15-19)
            instruction = utils::setBitsInRange(instruction, op.rs1, 15, 5);
            // Set immediate (bits 20-31)
            instruction = utils::setBitsInRange(instruction, op.immediate, 20, 12);

            if (op.funct3 == 0x5 && op.opString == "SRAI") {
                // For SRAI, set funct7 (upper 7 bits of immediate) to 0x20
                instruction = utils::setBitsInRange(instruction, 0x20, 25, 7);
            }
            return instruction; 
        default: 
            throw std::invalid_argument("Unsupported opcode in InstTranslator");
    }
}