#pragma once

#include <cstdint>
// We do not use iostream in the header file to avoid unnecessary dependencies
// #include <iostream>

// We use a namespace with a name for organisation and to avoid polluting the global namespace with utility functions
// Different to blank namespace
namespace utils {

    // returns the bits in the specified range [start, start + length) from the given value
    inline uint32_t selectBits(uint32_t value, unsigned int start, unsigned int length) {
        // Create a mask with 'length' number of 1s
        uint32_t mask = (static_cast<uint32_t>(1) << length) - 1;
        
        // Shift the value right to align the desired bits, then apply mask
        return (value >> start) & mask;
    }

    // Sets bits in the specified range [start, start + length) to the provided bitsToSet value
    template<typename T, typename U>
    T setBitsInRange(T value, U bitsToSet, unsigned int start, unsigned int length) {
        // Create a mask with 'length' number of 1s
        T mask = ((static_cast<T>(1) << length) - 1) << start;
        
        // Clear the bits in the specified range
        value &= ~mask;
        
        // Set the new bits in the specified range
        value |= (bitsToSet << start) & mask;
        
        return value;
    } 

    // print address in hex format with leading zeros and 0x prefix
    void printAddress(uint32_t address);
}