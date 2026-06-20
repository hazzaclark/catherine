// COPYRIGHT (C) HARRY CLARK 2026
// HITACHI SUPERH INSTRUCTION DECODER

// NESTED INCLUDES

#include "common.h"
#include "instructions/instruction.h"
#include "instructions/instructionDSP.h"

// SYSTEM INCLUDES

#include <assert.h>

int main(void)
{
    volatile U32 DSP_WORD[] =
    {
        0x1B6D1E06,
    };

    SH_DSP_INSTRUCTION DSP_INSTR = {0};
    U32 DSP_ADDRESS = 0x06000000;
    UNK DSP_WORD_COUNT = sizeof(DSP_WORD) / sizeof(DSP_WORD[0]);

    for (UNK INDEX = 0; INDEX < DSP_WORD_COUNT; INDEX++)
    {
        CATH_DSP_INSTRUCTION_INIT(&DSP_INSTR, DSP_WORD[INDEX], DSP_ADDRESS);
        CATH_DSP_INSTRUCTION_PROCESS(&DSP_INSTR);

        UNK BUFFER_SIZE = CATH_DSP_INSTRUCTION_GET_SIZE(&DSP_INSTR);
        char* BUFFER = malloc(BUFFER_SIZE + 1);
        assert(BUFFER != NULL);

        CATH_DSP_INSTRUCTION_DISASM(&DSP_INSTR, BUFFER, BUFFER_SIZE + 1);
        printf("0x%08X:  0x%08X  %s\n", DSP_ADDRESS, DSP_WORD[INDEX], BUFFER);

        free(BUFFER);
        DSP_ADDRESS += 4;
    }

    return 0;
}