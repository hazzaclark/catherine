// COPYRIGHT (C) HARRY CLARK 2025
// HITACHI SUPERH INSTRUCTION DECODER

// THIS FILE PERTAINS TOWARDS THE MODULARISATION AND LAYOUT OF THE REGISTERS
// IDENTIFIERS, THEIR RESPECTIVE CHARACTERISTICS, THE CONCATENATION OF TYPES
// AND HELPER FUNCTIONS - ALL PERTAINING TOWARDS THE REGISTERS

#ifndef CATH_REGISTER_H
#define CATH_REGISTER_H

#if defined(USE_CATH_REG)
    #define USE_CATH_REG
#else
    #define USE_CATH_REG

#ifdef __cplusplus
extern "C" {
#endif

    // NESTED INCLUDES  

    #include "util.h"
    #include "instructions/instruction.h"

    #include "enums/register.h"

    // DEFINE THE BASIS FOR THE LABELS ENCOMPASSING ALL REGISTER TYPES
    extern const char* CATH_GPR_NAMES[SH2_REG_MAX][2];
    extern const char* CATH_CTRL_NAMES[SH2_REG_CTRL_MAX];
    extern const char* CATH_SYS_NAMES[SH2_REG_SYS_MAX];

    // DEPRACATED
    extern const char* CATH_MISC_NAMES[CATH_INSTR_ID_ALL_MAX][2];

    //////////////////////////////////////////
    //         FUNCTION PROTOTYPES
    //////////////////////////////////////////

    const char* CATH_REGISTER_GET_GPRNAME(U8);
    const char* CATH_REGISTER_GET_CTRLNAME(U8);
    const char* CATH_REGISTER_GET_SYSNAME(U8);

#ifdef __cplusplus
}

#endif
#endif
#endif
