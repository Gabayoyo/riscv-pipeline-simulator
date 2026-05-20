#pragma once

// Don't use fs namespace as it is a header file
#include <filesystem>
#include <vector>

// Main parser class responsible for parsing assembly code into 32-bit instruction format
class Parser {
    public:
        std::vector<uint32_t> parseFile(const std::filesystem::path& filepath);
        Parser() = default;
};