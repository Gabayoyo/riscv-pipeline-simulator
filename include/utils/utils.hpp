#pragma once

#include <cstdint>
#include <iostream>

namespace utils {

    
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
}