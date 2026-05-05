// COPYRIGHT (C) HARRY CLARK 2025
// HITACHI SUPERH INSTRUCTION DECODER

// NESTED INCLUDES

#include "instructions/instruction_sh2.hpp"

using namespace catherine;

int main(void)
{
    std::printf("HARRY CLARK - HITACHI SUPERH INSTRUCTION DECODER\n");

    CATH_INSTRUCTION_BUILD_ID_TABLE();
    
    U16 WORD = {0x2231};
    U32 PC = 0x06002EEA;

    catherine::CATH_INSTRUCTION_SH2 INSTR(WORD, PC);
    std::printf("0x%08X: 0x%04X: %s\n", INSTR.CATH_GET_RAW_PC(), WORD, INSTR.CATH_DISASSEMBLE_INSTR().c_str());
    return 0;
}
