// COPYRIGHT (C) HARRY CLARK 2025
// HITACHI SUPERH INSTRUCTION DECODER

// NESTED INCLUDES

#include "common.h"
#include "instructions/instruction.h"

int main(void)
{
    printf("HARRY CLARK - HITACHI SUPERH INSTRUCTION DECODER\n");
    U16 WORD[] = {0x2FE6, 0x2FD6, 0x6E43, 0x2FC6, 0x2FB6, 0x2FA6, 0x6A53,
                    0x4F22, 0x7FFC, 0x60E2, 0x2008, 0x8F07, 0x9B20};
    U32 ADDRESS = 0x0607074E;
    
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
