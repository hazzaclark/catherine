// COPYRIGHT (C) HARRY CLARK 2025
// HITACHI SUPERH INSTRUCTION DECODER

// NESTED INCLUDES

#include "instructions/instruction_sh2.hpp"

using namespace catherine;

int main(void)
{
    std::printf("HARRY CLARK - HITACHI SUPERH INSTRUCTION DECODER\n");
    U16 WORD = {0xA100};
    U32 PC = 0x06000000;

    catherine::CATH_INSTRUCTION_SH2 INSTR(WORD, PC);
    std::printf("0x%08X: 0x%X: %s\n", INSTR.CATH_GET_RAW_PC(),  WORD, INSTR.CATH_DISASSEMBLE_INSTR().c_str());
    return 0;
}
