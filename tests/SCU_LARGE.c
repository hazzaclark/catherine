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
        0x00001C02,
        0x00003600,
        0xC001000C,
        0x00001C00,
        0x00001D3F,
        0x00003704,
        0x00003604,
        0xC001010D,
        0xD3400008,
        0x00001D3F,
        0x00003A05,
        0x00001B0C,
        0x02591F00,
        0x035B1E00,
        0x1B5D1D00,
        0x190D1440,
    };  

    SH_DSP_INSTRUCTION DSP_INSTR = {0};
    U32 DSP_ADDRESS = 0x00000000;
    UNK DSP_WORD_COUNT = sizeof(WORD) / sizeof(WORD[0]);

    for (UNK INDEX = 0; INDEX < DSP_WORD_COUNT; INDEX++)
    {
        CATH_DSP_INSTRUCTION_INIT(&DSP_INSTR, WORD[INDEX], DSP_ADDRESS);
        CATH_DSP_INSTRUCTION_PROCESS(&DSP_INSTR);

        UNK BUFFER_SIZE = CATH_DSP_INSTRUCTION_GET_SIZE(&DSP_INSTR);
        char* BUFFER = malloc(BUFFER_SIZE + 1);
        assert(BUFFER != NULL);

        CATH_DSP_INSTRUCTION_DISASM(&DSP_INSTR, BUFFER, BUFFER_SIZE + 1);
        printf("0%X:  0x%08X  %s\n", DSP_ADDRESS, WORD[INDEX], BUFFER);

        free(BUFFER);
        DSP_ADDRESS++;
    }

    return 0;
}