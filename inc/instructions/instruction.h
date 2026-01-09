// COPYRIGHT (C) HARRY CLARK 2025
// HITACHI SUPERH INSTRUCTION DECODER

// THIS FILE PERTAINS TOWARDS THE MODULARISATION AND LAYOUT OF THE INSTRUCTIONS
// IDENTIFIERS, THEIR RESPECTIVE CHARACTERISTICS, THE CONCATENATION OF TYPES
// AND HELPER FUNCTIONS - ALL PERTAINING TOWARDS THE INSTRUCTIONS

#ifndef CATH_INSTR_H
#define CATH_INSTR_H

// NESTED INCLUDES

#include <common.h>

#include "util.h"
#include "instructions/operands.h"
#include "enums/instructions.h"
#include "enums/category.h"

// SYSTEM INCLUDES

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

#if defined(CATH_INSTR)
    #define CATH_INSTR
#else
    #define CATH_INSTR

#ifdef __cplusplus
extern "C" {
#endif

    // DEFINE THE BASIS FOR THE DESCRIPTOR
    // OF EACH INSTRUCTION TYPE
    typedef struct SH_DESCRIPTOR
    {   
        SH_OPERAND_TYPE OPERAND_TYPE[OPERAND_MAX+1];

        bool IS_BRANCH;         // LOCAL BRANCH FOR CURRENT SYMBOL
        bool IS_JUMP;           // SAME CONDITION AS BRANCH EXCEPT FOR JUMP ROUTINES
        bool IS_JUMP_ADDRESS;    // DOES THE JUMP ENCOMPASS ANY SORT OF EA?
        bool IS_TRAP;           // DO WE HAVE SUPERVISOR MODE?
        bool IS_HALT;           // HAS THE HALT LINE BEEN ACTIVATED?
        
        bool IS_FLOAT;
        bool IS_UNSIGNED;

        bool HAS_DELAY_SLOT;    // DOES THE INSTRUCTION HAVE A DELAY SLOT FOR IMMEDIATE BRANCH?

    } SH_DESCRIPTOR;

    // DEFINE THE BASIS FOR ACCESSING INSTRUCTION
    // TYPES AND THEIR CHARACTERISTICS
    typedef struct SH_INSTRUCTION
    {
        CATH_INSTR_ID INSTR_ID;
        CATH_INSTR_ID_TYPE ID_TYPE;
        const SH_DESCRIPTOR* DESCRIPTOR;
        CATH_INSTR_CAT CATEGORY;
        
        U32 FLAGS;
        U32 PC;
        U16 WORD;
        U32 BITS;

    } SH_INSTRUCTION;

    typedef struct SH_ENTRY
    {
        U16 MASK;
        U16 PATTERN;
        CATH_INSTR_ID ID;

    } SH_ENTRY;

    // PRE PROCESSOR DIRECTIVES TO HELP WITH ACCESS TO SPECIFIC CHARACTERISTICS CPU-WISE
    // ACCEES TO OPCODE WORD, FUNCTION ID AND CALLBACKS
    
    // ACCESS OPCODE WORD VALUES BASED ON TOP NTH BITS
    #define         SH2_INSTR_GET_OPCODE4(VALUE)                (CATH_SHIFT_R((VALUE)->WORD, 12, 4))
    #define         SH2_INSTR_GET_OPCODE8(VALUE)                (CATH_SHIFT_R((VALUE)->WORD, 8, 8))
    #define         SH2_INSTR_GET_OPCODE12(VALUE)               (CATH_SHIFT_R((VALUE)->WORD, 4, 12))

    // ACCESS REGISTER FIELDS
    #define         SH2_INSTR_GET_RN(VALUE)                     (CATH_SHIFT_R((VALUE)->WORD, 8, 4))
    #define         SH2_INSTR_GET_RM(VALUE)                     (CATH_SHIFT_R((VALUE)->WORD, 4, 4))

    // ACCESS IMMEDIATE/DISP FIELDS
    #define         SH2_INSTR_GET_IMM4(VALUE)                   (CATH_SHIFT_R((VALUE)->WORD, 0, 4))
    #define         SH2_INSTR_GET_IMM8(VALUE)                   (CATH_SHIFT_R((VALUE)->WORD, 0, 8))
    #define         SH2_INSTR_GET_DISP4(VALUE)                  (CATH_SHIFT_R((VALUE)->WORD, 0, 4))
    #define         SH2_INSTR_GET_DISP8(VALUE)                  (CATH_SHIFT_R((VALUE)->WORD, 0, 8))
    #define         SH2_INSTR_GET_DISP12(VALUE)                 (CATH_SHIFT_R((VALUE)->WORD, 0, 12))

    #define         SH2_INSTR_DISP_SIGNBIT                      0x800
    #define         SH2_INSTR_DISP_SIGN_MASK                    0xFFFFF000

    #define         SH2_INSTR_GET_IMM(VALUE)

    // ACCESS CACHE CONTROL
    #define         SH2_INSTR_GET_CACHE(VALUE)                  (CATH_SHIFT_R((VALUE)->WORD, 0, 8))
    #define         SH2_INSTR_GET_MAC(VALUE)                    (CATH_SHIFT_R((VALUE)->WORD, 1, 1))
    #define         SH2_INSTR_GET_IMASK(VALUE)                  (CATH_SHIFT_R((VALUE), 4, 4))

    // ACCESS COMMON ADDRESSING MODES (SATURN SPECIFIC)
    #define         SH2_INSTR_GET_GBR_DISP(VALUE)               (CATH_SHIFT_R((VALUE)->WORD, 0, 8))
    #define         SH2_INSTR_GET_PC_DISP(VALUE)                (CATH_SHIFT_R((VALUE)->WORD, 0, 8))

    #define         SH2_BYTE_ALIGN(PC)                          ((PC) + 4)
    #define         SH2_WORD_ALIGN(PC)                          (((PC) + 4) & ~1)
    #define         SH2_LONG_ALIGN(PC)                          (((PC) + 4) & ~3)

    #define         SH2_INSTR_VALID(VALUE)                      ((VALUE)->INSTR_ID == CATH_INSTR_ID_INVALID || (VALUE)->DESCRIPTOR == NULL)

    /////////////////////////////////////////////////////////
    //                FUNCTION PROTOTYPES
    /////////////////////////////////////////////////////////

    void CATH_INSTRUCTION_INIT(SH_INSTRUCTION*, U16, U32);
    void CATH_INSTRUCTION_PROCESS(SH_INSTRUCTION*);
    S32 CATH_INSTRUCTION_GET_IMM(const SH_INSTRUCTION*);
    S32 CATH_INSTRUCTION_GET_DISP(const SH_INSTRUCTION*);

    inline U16 CATH_GET_RAW(const SH_INSTRUCTION* INSTR) { return INSTR->WORD; }
    inline U32 CATH_GET_PC(const SH_INSTRUCTION* INSTR) { return INSTR->PC; }
    inline S32 CATH_GET_BRANCH_OFFSET(const struct SH_INSTRUCTION* INSTR) 
    { 
        S32 DISP = CATH_INSTRUCTION_GET_DISP(INSTR); 
        return INSTR->PC + 4 + (DISP * 2); 
    }

    UNK CATH_INSTRUCTION_DISASM_DATA(const SH_INSTRUCTION*, char*);
    UNK CATH_INSTRUCTION_GET_SIZE(const SH_INSTRUCTION*);

    extern const SH_DESCRIPTOR INSTR_DESCRIPTORS[];
    extern const char* CATH_INSTR_ID_NAMES[];
    extern const char* CATH_GET_OPCODE_NAME(CATH_INSTR_ID INSTR_ID);

    UNK CATH_INSTRUCTION_DISASM_INSTR(const SH_INSTRUCTION*, char*);
    UNK CATH_INSTRUCTION_DISASM_OPERAND(const SH_INSTRUCTION*, char*);
    UNK CATH_INSTRUCTION_DISASM(const SH_INSTRUCTION*, char*);

#ifdef __cplusplus
}
#endif
#endif
#endif
