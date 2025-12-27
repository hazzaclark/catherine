// COPYRIGHT (C) HARRY CLARK 2025
// HITACHI SUPERH INSTRUCTION DECODER

// NESTED INCLUDES

#include "instructions/instruction_sh2.hpp"

using namespace catherine;

int main(void)
{
    U16 WORD = 0xDF1B;
    U32 PC = 0x0600000;

    catherine::CATH_INSTRUCTION_SH2 INSTR(WORD, PC);
    printf("0x%X: %s\n", WORD, INSTR.CATH_DISASSEMBLE_INSTR().c_str());
    return 0;
}