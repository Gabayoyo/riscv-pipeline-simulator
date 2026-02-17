#pragma once

#include "fetch/instMemory.hpp"

#include <filesystem>

#include <string>
using namespace std;
namespace fs = std::filesystem;

class instConstructor {
    public:
        instConstructor() = default;

        InstMemory constructInstMemoryFromFile(fs::path filepath);

};