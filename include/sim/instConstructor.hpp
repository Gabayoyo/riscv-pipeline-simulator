#pragma once

#include "instMemory.hpp"

#include <filesystem>

#include <string>
namespace fs = std::filesystem;

class instConstructor {
    public:
        instConstructor() = default;

        InstMemory constructInstMemoryFromFile(std::string filepath);

};