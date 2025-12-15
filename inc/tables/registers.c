// COPYRIGHT (C) HARRY CLARK 2025
// HITACHI SUPERH INSTRUCTION DECODER

// THIS FILE PERTAINS TOWARDS THE MODULARISATION AND LAYOUT OF THE REGISTERS
// IDENTIFIERS, THEIR RESPECTIVE CHARACTERISTICS, THE CONCATENATION OF TYPES
// AND HELPER FUNCTIONS - ALL PERTAINING TOWARDS THE REGISTERS

// NESTED INCLUDES  

#include "instructions/register.h"

const char* CATH_GPR_NAMES[SH2_REG_MAX][2] = 
{
    [SH2_REG_R0]  = { "R0",  "r0"  },
    [SH2_REG_R1]  = { "R1",  "r1"  },
    [SH2_REG_R2]  = { "R2",  "r2"  },
    [SH2_REG_R3]  = { "R3",  "r3"  },
    [SH2_REG_R4]  = { "R4",  "r4"  },
    [SH2_REG_R5]  = { "R5",  "r5"  },
    [SH2_REG_R6]  = { "R6",  "r6"  },
    [SH2_REG_R7]  = { "R7",  "r7"  },
    [SH2_REG_R8]  = { "R8",  "r8"  },
    [SH2_REG_R9]  = { "R9",  "r9"  },
    [SH2_REG_R10] = { "R10", "r10" },
    [SH2_REG_R11] = { "R11", "r11" },
    [SH2_REG_R12] = { "R12", "r12" },
    [SH2_REG_R13] = { "R13", "r13" },
    [SH2_REG_R14] = { "R14", "r14" },
    [SH2_REG_R15] = { "R15", "r15" }
};

const char* CATH_CTRL_NAMES[SH2_REG_CTRL_MAX] = 
{
    [SH2_REG_SR] = "SR",
    [SH2_REG_GBR] = "GBR",
    [SH2_REG_VBR] = "VBR",
};

const char* CATH_SYS_NAMES[SH2_REG_SYS_MAX] =
{
    [SH2_REG_MACH] = "MACH",
    [SH2_REG_MACL] = "MACL",
    [SH2_REG_PR] = "PR",
}; 