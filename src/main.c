// COPYRIGHT (C) HARRY CLARK 2025
// HITACHI SUPERH INSTRUCTION DECODER

// NESTED INCLUDES

#include "common.h"
#include "instructions/instruction.h"

// SYSTEM INCLUDES

#include <assert.h>

int main(void)
{
    printf("HARRY CLARK - HITACHI SUPERH INSTRUCTION DECODER\n");
    U16 WORD[] = {0xD21C, 0xE310, 0x2230, 0xE301, 0x2230, 0xDF1B, 0xD01B, 0x401E, 0xE000, 0xC11B, 0xC02C, 0xC02D, 0xD219,
        0x6020, 0xE000, 0x2200, 0xD818, 0xE9FF, 0x2891, 0xD318, 0x6432, 0xD215, 0x9120, 0x6020, 0x2018, 0x8DFC, 0x7401,
        0xE100, 0x2210, 0x6032, 0x4011, 0x8900, 0xE400, 0x2342, 0xD00D, 0x401E, 0xC42C, 0x6803, 0xC42D, 0x3080, 0x891E,
            0x6803, 0x7001, 0xC907, 0xC02D, 0xD30C, 0x4808, 0x4800, 0x338C, 0x6836, 0x6083, 0xC20A, 0x480B, 0x0009, 0xA036,
            0x0009};

    U32 ADDRESS = 0x06005F70;
    char* BUFFER;
    UNK BUFFER_SIZE;
    SH_INSTRUCTION INSTR;
    
    for(UNK INDEX = 0; INDEX < sizeof(WORD) / sizeof(WORD[0]); INDEX++)
    {           
        BUFFER_SIZE = CATH_INSTRUCTION_GET_SIZE(&INSTR);
        BUFFER = malloc(BUFFER_SIZE + 1);

        assert(BUFFER != NULL);

        CATH_INSTRUCTION_INIT(&INSTR, WORD[INDEX], ADDRESS);
        CATH_INSTRUCTION_PROCESS(&INSTR);

        CATH_INSTRUCTION_DISASM(&INSTR, BUFFER);
        
        printf("0x%08X: 0x%04X -> %s\n", ADDRESS, WORD[INDEX], BUFFER);
        ADDRESS += 2;
    }
    
    free(BUFFER);
    return 0;
}
