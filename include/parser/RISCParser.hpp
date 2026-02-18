#pragma once

#include "fetch/instMemory.hpp"
#include <filesystem>
namespace fs = std::filesystem;

class RISCparser {
    public:
        RISCparser() = default;

        InstMemory parseRISCFileToInstMemory(fs::path filepath);
};