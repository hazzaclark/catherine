// COPYRIGHT (C) HARRY CLARK 2025
// HITACHI SUPERH INSTRUCTION DECODER

// THIS FILE PERTAINS TOWARDS THE MODULARISATION AND LAYOUT OF THE INSTRUCTIONS
// IDENTIFIERS, THEIR RESPECTIVE CHARACTERISTICS, THE CONCATENATION OF TYPES
// AND HELPER FUNCTIONS - ALL PERTAINING TOWARDS THE INSTRUCTIONS

#ifndef CATH_INSTR_H
#define CATH_INSTR_H

// NESTED INCLUDES

#include <common.h>

#include "instructions/operands.h"
#include "enums/instructions.h"

// SYSTEM INCLUDES

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#if defined(CATH_INSTR)
    #define CATH_INSTR
#else
    #define CATH_INSTR

#ifdef __cplusplus
extern "C" {
#endif

    // DEFINE THE BASIS FOR THE DESCRIPTOR
    // OF EACH INSTRUCTION TYPE
    typedef struct  
    {   
        SH_OPERAND_TYPE OPERAND_TYPE;
        CATH_INSTR_ID INSTR_ID;

        bool IS_BRANCH;         // LOCAL BRANCH FOR CURRENT SYMBOL
        bool IS_JUMP;           // SAME CONDITION AS BRANCH EXCEPT FOR JUMP ROUTINES
        bool IS_JUMP_ADDRESS;    // DOES THE JUMP ENCOMPASS ANY SORT OF EA?
        bool IS_TRAP;           // DO WE HAVE SUPERVISOR MODE?
        bool IS_HALT;           // HAS THE HALT LINE BEEN ACTIVATED?
        
        bool IS_FLOAT;

    } SH_DESCRIPTOR;

    // DEFINE THE BASIS FOR ACCESSING INSTRUCTION
    // TYPES AND THEIR CHARACTERISTICS
    typedef struct
    {
        U32 WORD;
        U32 BITS;

    } SH_INSTRUCTION;


#ifdef __cplusplus
}
#endif
#endif
#endif
