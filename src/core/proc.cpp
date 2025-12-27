#include <iostream>
using namespace std;

#include "decode/regfile/regfile.hpp"
#include "decode/decoder/decodedInst.hpp"
#include "sim/RISCop.hpp"
#include "sim/instTranslator.hpp"
#include "utils/utils.hpp"
#include "decode/decoder/decoder.hpp"

int main() {

    Regfile rf;
    RISCop op("ADDI x2, x2, x4"); // RISCop object constructed from string
    InstTranslator translator;
    uint32_t inst32 = translator.instTo32Bit(op); // translates to a raw 32-bit instruction
    Decoder decoder;
    DecodedInst decodedInst = decoder.decodeInstruction(inst32); // decodes the instruction as if fetched from program memory
    return 0;
}