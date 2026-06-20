// COPYRIGHT (C) HARRY CLARK 2026
// HITACHI SUPERH INSTRUCTION DECODER

// NESTED INCLUDES

#include "common.h"
#include "instructions/instruction.h"

// SYSTEM INCLUDES

#include <assert.h>

int main(void)
{
    printf("HARRY CLARK - HITACHI SUPERH INSTRUCTION DECODER\n");

    CATH_INSTRUCTION_BUILD_ID_TABLE();
    
    volatile U16 WORD[] = 
    {
        0xC6BB,
    };

    SH_INSTRUCTION INSTR = {0};
    U32 ADDRESS = 0x06000000;
    UNK WORD_COUNT = sizeof(WORD) / sizeof(WORD[0]);

    for (UNK INDEX = 0; INDEX < WORD_COUNT; INDEX++)
    {
        CATH_INSTRUCTION_INIT(&INSTR, WORD[INDEX], ADDRESS);
        CATH_INSTRUCTION_PROCESS(&INSTR);

        UNK BUFFER_SIZE = CATH_INSTRUCTION_GET_SIZE(&INSTR);
        char* BUFFER = malloc(BUFFER_SIZE + 1);
        assert(BUFFER != NULL);

        CATH_INSTRUCTION_DISASM(&INSTR, BUFFER, BUFFER_SIZE + 1);
        printf("0x%08X:  %04X  %s\n", ADDRESS, WORD[INDEX], BUFFER);

        free(BUFFER);
        ADDRESS += 2;
    }

    return 0;
}