// COPYRIGHT (C) HARRY CLARK 2025
// HITACHI SUPERH INSTRUCTION DECODER

// NESTED INCLUDES

#include "common.h"
#include "instructions/instruction.h"

int main(void)
{
    printf("HARRY CLARK - HITACHI SUPERH INSTRUCTION DECODER\n");
    U16 WORD[] = {0x74F8, 0x4710, 0x8FEA, 0x73F8, 0xD808, 0x6002, 0xE1FF, 0x2011, 0x3098, 0x401E};
    U32 ADDRESS = 0x06000000;
    
    for(UNK INDEX = 0; INDEX < sizeof(WORD) / sizeof(WORD[0]); INDEX++)
    {
        SH_INSTRUCTION INSTR;
        char BUFFER[128];
        
        CATH_INSTRUCTION_INIT(&INSTR, WORD[INDEX], ADDRESS);
        CATH_INSTRUCTION_PROCESS(&INSTR);
        CATH_INSTRUCTION_DISASM(&INSTR, BUFFER);
        
        printf("0x%08X: 0x%04X -> %s\n", ADDRESS, WORD[INDEX], BUFFER);
        ADDRESS += 2;
    }
    
    return 0;
}
