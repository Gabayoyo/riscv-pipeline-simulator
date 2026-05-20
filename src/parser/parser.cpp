#include <asm/parser.hpp>
#include <utils/utils.hpp>

#include <map>
#include <sstream>
#include <fstream>
#include <iostream>

using utils::setBitsInRange;

// Namespace is used here as the tokenise function is only used in this file and doesn't need to be exposed outside
namespace {
    enum class Format  { R, I, S, B, U, J };

    struct InstrInfo {
        const char* mnemonic;
        uint32_t opcode;
        uint8_t funct3;
        uint8_t funct7;
        Format format;
    };

    // RISC string to opcode/funct3/funct7 mapping
    static constexpr InstrInfo instructionInfo[] = {
        // R-type
        {"ADD", 0b0110011, 0x0, 0x00, Format::R},
        {"SUB", 0b0110011, 0x0, 0x20, Format::R},
        {"AND", 0b0110011, 0x7, 0x00, Format::R},
        {"OR",  0b0110011, 0x6, 0x00, Format::R},
        {"XOR", 0b0110011, 0x4, 0x00, Format::R},
        {"SRA", 0b0110011, 0x5, 0x20, Format::R},
        {"SLL", 0b0110011, 0x1, 0x00, Format::R},
        {"SRL", 0b0110011, 0x5, 0x00, Format::R},
        {"SLT", 0b0110011, 0x2, 0x00, Format::R},
        {"SLTU",0b0110011, 0x3, 0x00, Format::R},
        // I-type
        {"ADDI", 0b0010011, 0x0, 0x00, Format::I},
        {"XORI", 0b0010011, 0x4, 0x00, Format::I},
        {"ORI",  0b0010011, 0x6, 0x00, Format::I},
        {"ANDI", 0b0010011, 0x7, 0x00, Format::I},
        {"SLLI", 0b0010011, 0x1, 0x00, Format::I},
        {"SRLI", 0b0010011, 0x5, 0x00, Format::I},
        {"SRAI", 0b0010011, 0x5, 0x20, Format::I}, // imm[11:5] = 0x20 for SRAI
    };

    // tokenizes a line of assembly code
    // example: "ADD x1, x2, x3" -> ["ADD", "x1", "x2", "x3"]
    std::vector<std::string> tokenise(const std::string& line) {
        std::vector<std::string> tokens;
        std::string clean;

        for (char c : line)
            clean += (c == ',') ? ' ' : c;

        std::istringstream ss(clean);
        std::string token;
        while (ss >> token)
            tokens.push_back(token);

        return tokens;
    }

    uint8_t parseReg(const std::string& token) {
        if (token.empty() || token[0] != 'x')
            throw std::invalid_argument("Invalid register: " + token);
        return static_cast<uint8_t>(std::stoi(token.substr(1)));
    }

    int32_t parseImm(const std::string& token) {
        return static_cast<int32_t>(std::stoi(token));
    }

    uint32_t parseIType(const std::vector<std::string>& tokens, const InstrInfo& info) {
        if (tokens.size() != 4) {
            throw std::invalid_argument("Invalid number of tokens for I-type instruction");
        }
        uint32_t instruction = 0;
        instruction = setBitsInRange(instruction, info.opcode, 0, 7);
        instruction = setBitsInRange(instruction, parseReg(tokens[1]), 7, 5); // rd
        instruction = setBitsInRange(instruction, info.funct3, 12, 3);
        instruction = setBitsInRange(instruction, parseReg(tokens[2]), 15, 5); // rs1
        instruction = setBitsInRange(instruction, parseImm(tokens[3]), 20, 12); // immediate

        if (info.funct3 == 0x5 || info.funct3 == 0x1) {
            // For SRAI, set funct7 (upper 7 bits of immediate) to 0x20
            instruction = setBitsInRange(instruction, 0x20, 25, 7);
        }
        return instruction;
    }

    uint32_t parseLine(const std::string& line) {
        auto tokens = tokenise(line);
        
        // find instruction info based on instruction mnemonic (first token)
        auto info = std::find_if(
            std::begin(instructionInfo),
            std::end(instructionInfo),
            [&](const InstrInfo& i) {
                return i.mnemonic == tokens[0];
            }
        );

        if (info == std::end(instructionInfo)) {
            throw std::invalid_argument("Unknown instruction");
        }

        switch (info->format) {
            case Format::I:
                return parseIType(tokens, *info);
            default:
                throw std::invalid_argument("Unsupported instruction format");
        }
    }
}

std::vector<uint32_t> Parser::parseFile(const std::filesystem::path& filepath) {
    std::vector<uint32_t> instructions;
    std::ifstream file(filepath);
    std::string line;

    while (std::getline(file, line)) {
        if (!line.empty()) {
            instructions.push_back(parseLine(line));
        }
    }
    return instructions;
}
