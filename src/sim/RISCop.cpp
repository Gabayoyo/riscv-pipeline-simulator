#include "sim/RISCop.hpp"
#include "sim/opcodeDict.hpp"
#include <regex>
#include <iostream>

/* 
The RISC operation constructor using regex to break down into various fields.
This class is not for decoding directly, but to parse a RISC operation string
into its fields/components for later encoding into the 32-bit instruction format.
*/
// RISCop::RISCop(std::string inputOp) : opString(inputOp) {
// 
//     // regex to extract operation
//     std::regex opPattern(R"(^(\S+))");
//     std::regex rdPattern(R"(\s+([^,]+))");
//     std::regex rsPattern(R"(\s+[^,]+,\s+([^,]+), ([^,]+))");
//     std::regex offsetPattern(R"(,\s*(-?\d*)\(([^)]+)\))");
//     std::smatch match;
// 
//     std::string opAsString;
// 
//     // extract operation for opcode
//     if (std::regex_search(inputOp, match, opPattern)) {
//         opAsString = match.str(1);
//         InstrEncoding instrEncoding = opcodeDict[opAsString];
//         opcode = instrEncoding.opcode;
//         funct3 = instrEncoding.funct3;
//         funct7 = instrEncoding.funct7;
// 
//     } else throw std::invalid_argument("Invalid RISC operation string");
//     
//     // extracting rd
//     if (std::regex_search(inputOp, match, rdPattern)) {
//         rd = std::stoi(match.str(1).substr(1,2));
//     }
//     else throw std::invalid_argument("Invalid RISC rd string");
// 
//     // extracting rs1 and offset if applicable
//     if (std::regex_search(inputOp, match, offsetPattern)) {
//         // if (register) instead of offset(register), string is empty
//         // handle as zero offset
//         if (match.str(1).empty()) {
//             offset = 0;
//         } else {
//             offset = std::stoi(match.str(1));
//         }
//         rs1 = std::stoi(match.str(2).substr(1,2));
//     }
//     // must be rs1 and rs2 format
//     else if (std::regex_search(inputOp, match, rsPattern)) {
//         offset = 0;
//         rs1 = std::stoi(match.str(1).substr(1,2));
//         if (match.str(2)[0] == 'x') {
//             rs2 = std::stoi(match.str(2).substr(1,2));
//         } else if (match.str(2)[0] == '-') {
//             immediate = 0 - std::stoi(match.str(2)); // if '-' sign, then make it negative
//         } else {
//             immediate = std::stoi(match.str(2));
//         }
//     }
//     else throw std::invalid_argument("Invalid RISC rs strings");
// }

RISCop::RISCop(std::string inputString) {
    std::regex opPattern(R"(^(\S+))");
    std::smatch match;

    if (std::regex_search(inputString, match, opPattern)) {
        opString = match.str(1);
    } else throw std::invalid_argument("Invalid RISC operation string");
}

IType::IType(std::string inputString) : RISCop(inputString) {
    instrType = InstructionType::I_TYPE;
    IType::parse(inputString);
}

void IType::parse(const std::string& inputString) {
    std::regex rdPattern(R"(\s+([^,]+))");
    std::regex rsPattern(R"(\s+[^,]+,\s+([^,]+), ([^,]+))");
    std::regex offsetPattern(R"(,\s*(-?\d*)\(([^)]+)\))");
    std::smatch match;

    // extracting rd
    if (std::regex_search(inputString, match, rdPattern)) {
        rd = std::stoi(match.str(1).substr(1,2));
    }
    else throw std::invalid_argument("Invalid RISC rd string");

    // extracting rs1 and offset if applicable
    if (std::regex_search(inputString, match, offsetPattern)) {
        // if (register) instead of offset(register), string is empty
        // handle as zero offset
        if (match.str(1).empty()) {
            offset = 0;
        } else {
            offset = std::stoi(match.str(1));
        }
        rs1 = std::stoi(match.str(2).substr(1,2));
    }
    // invalid format for I-Type
    else throw std::invalid_argument("Invalid RISC rs and offset strings for I-Type instruction");
}