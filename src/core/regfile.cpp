#include "core/regfile.hpp"
#include <iostream>
using namespace std;

// register read function
uint32_t Regfile::read(uint16_t addr) const {
    if (addr < 32) {
        return regs[addr];
    } else throw std::out_of_range("Register address out of bounds");
}

// register write function
// register 0 is hardwired to 0 and cannot be written to
void Regfile::write(uint16_t addr, uint32_t data) {
    if (addr < 32 && addr != 0) {
        regs[addr] = data;
    } else throw std::out_of_range("Register address out of bounds");
}

// printing functions for debugging
void Regfile::printAll() const {
    for (int i = 0; i < 32; i++) {
        cout << dec << "x" << i << ": 0x" << hex << regs[i] << endl;
    }
}

void Regfile::printReg(uint16_t addr) const {
    if (addr < 32) {
        cout << dec << "x" << addr << ": 0x" << hex << regs[addr] << endl;
    } else throw std::out_of_range("Register address out of bounds");
}