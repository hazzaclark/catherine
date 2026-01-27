// COPYRIGHT (C) HARRY CLARK 2025
// HITACHI SUPERH INSTRUCTION DECODER

// NESTED INCLUDES

#include "common.h"
#include "instructions/instruction.h"

int main(void)
{
    printf("HARRY CLARK - HITACHI SUPERH INSTRUCTION DECODER\n");
    U16 WORD[] = {0x937C, 0x0002, 0x2039, 0xCBF0, 0x400E, 0xE201, 0x9177, 0xD33D, 0x0323, 0x2120};
    U32 ADDRESS = 0x06004334;
    
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
