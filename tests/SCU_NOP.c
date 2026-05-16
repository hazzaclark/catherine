// COPYRIGHT (C) HARRY CLARK 2026
// HITACHI SUPERH INSTRUCTION DECODER

// NESTED INCLUDES

#include "instructions/instructionDSP.h"

// SYSTEM INCLUDES

#include <assert.h>

int main(void)
{
    volatile U32 WORD[] = 
    {
        0x041F0438,
        0x00000000,
        0x00001F0C,
    };  

    SH_DSP_INSTRUCTION DSP_INSTR = {0};
    U32 DSP_ADDRESS = 0x06000000;
    UNK DSP_WORD_COUNT = sizeof(WORD) / sizeof(WORD[0]);

    for (UNK INDEX = 0; INDEX < DSP_WORD_COUNT; INDEX++)
    {
        CATH_DSP_INSTRUCTION_INIT(&DSP_INSTR, WORD[INDEX], DSP_ADDRESS);
        CATH_DSP_INSTRUCTION_PROCESS(&DSP_INSTR);

        UNK BUFFER_SIZE = CATH_DSP_INSTRUCTION_GET_SIZE(&DSP_INSTR);
        char* BUFFER = malloc(BUFFER_SIZE + 1);
        assert(BUFFER != NULL);

        CATH_DSP_INSTRUCTION_DISASM(&DSP_INSTR, BUFFER);
        printf("0x%08X:  0x%08X  %s\n", DSP_ADDRESS, WORD[INDEX], BUFFER);

        free(BUFFER);
        DSP_ADDRESS += 4;
    }

    return 0;
}