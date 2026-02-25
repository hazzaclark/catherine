// COPYRIGHT (C) HARRY CLARK 2025
// HITACHI SUPERH INSTRUCTION DECODER

// THIS FILE PERTAINS TOWARDS THE MODULARISATION AND LAYOUT OF THE INSTRUCTIONS
// IDENTIFIERS, THEIR RESPECTIVE CHARACTERISTICS, THE CONCATENATION OF TYPES
// AND HELPER FUNCTIONS - ALL PERTAINING TOWARDS THE INSTRUCTIONS OF THE SCU DSP 

#ifndef CATH_INSTR_DSP_H
#define CATH_INSTR_DSP_H

#pragma once

// NESTED INCLUDES

#include "instructions/instruction.h"
#include "instructions/operandsDSP.h"
#include "enums/instructions.h"

#if defined(CATH_INSTR_DSP)
    #define CATH_INSTR_DSP
#else
    #define CATH_INSTR_DSP

#ifdef __cplusplus
extern "C" {
#endif

    // DEFINE THE BASIS FOR THE DESCRIPTOR
    // OF EACH INSTRUCTION TYPE
    typedef struct SH_DSP_DESCRIPTOR
    {
        SH_DSP_OPERAND_TYPE X_BUS_SRC;
        SH_DSP_OPERAND_TYPE Y_BUS_SRC;
        SH_DSP_OPERAND_TYPE D_BUS_SRC;
        SH_DSP_OPERAND_TYPE DEST;

        bool IS_ALU_OP;
        bool IS_MULTIPLY;
        bool IS_MOVE;
        bool IS_LOAD_STORE;

        bool IS_END;
        bool IS_END_JMP;
        bool IS_LOOP;
        bool IS_JUMP;
        bool IS_COND;

        bool HAS_EXE_FLAG;
        bool IS_NOP;

        U8 X_BUS : 1;
        U8 Y_BUS : 1;
        U8 D_BUS : 1;
        U8 WRITE_DEST : 1;

    } SH_DSP_DESCRIPTOR;

    // DEFINE THE BASIS FOR ACCESSING INSTRUCTION
    // TYPES AND THEIR CHARACTERISTICS
    typedef struct SH_DSP_INSTRUCTION
    {
        CATH_INSTR_ID_DSP INSTR_ID;
        CATH_INSTR_CAT CATEGORY;
        const SH_DSP_DESCRIPTOR* DESCRIPTOR;
        
        U32 FLAGS;
        U32 PC;
        U32 WORD;

    } SH_DSP_INSTRUCTION;

    // DEFINE THE BASIS FOR ACCESSING
    // THE PARALLELISED STATE OF THE DSP SLOTS
    // AND THEIR ACTIVITY
    typedef struct SH_DSP_PARALLEL_SLOT
    {
        SH_DSP_OPERAND_TYPE SOURCE;
        const char* DEST_NAME;
        bool IS_ACTIVE;
        bool IS_ALU;

    } SH_DSP_PARALLEL_SLOT;

    // PRE PROCESSOR DIRECTIVES TO HELP WITH ACCESS TO SPECIFIC CHARACTERISTICS CPU-WISE
    // ACCEES TO OPCODE WORD, FUNCTION ID AND CALLBACKS

    #define         SCU_DSP_GET_OPERAND(VALUE)                  (CATH_SHIFT_R((VALUE)->WORD, 26, 6))
    #define         SCU_DSP_GET_END(VALUE)                      (CATH_SHIFT_R((VALUE)->WORD, 15, 1))
    #define         SCU_DSP_GET_EXE(VALUE)                      (CATH_SHIFT_R((VALUE)->WORD, 14, 1))

    #define         SCU_DSP_GET_SRC_X(VALUE)                    (CATH_SHIFT_R((VALUE)->WORD, 20, 6))
    #define         SCU_DSP_GET_SRC_Y(VALUE)                    (CATH_SHIFT_R((VALUE)->WORD, 14, 6))
    #define         SCU_DSP_GET_SRC_D(VALUE)                    (CATH_SHIFT_R((VALUE)->WORD, 8, 6))

    #define         SCU_DSP_GET_DESTINATION(VALUE)              (CATH_SHIFT_R((VALUE)->WORD, 0, 8))

    #define         SCU_DSP_GET_ALU(VALUE)                      (CATH_SHIFT_R((VALUE)->WORD, 24, 4))

    #define         SCU_DSP_GET_IMM(VALUE)                      (CATH_SHIFT_R((VALUE)->WORD, 0, 8))
    #define         SCU_DSP_GET_IMM16(VALUE)                    (CATH_SHIFT_R((VALUE)->WORD, 0, 16))

    #define         SCU_DSP_GET_JUMP_ADDR(VALUE)                (CATH_SHIFT_R((VALUE)->WORD, 0, 8))
    #define         SCU_DSP_GET_COND(VALUE)                     (CATH_SHIFT_R((VALUE)->WORD, 8, 4))

    #define         SCU_DSP_PACK_OPERAND(WORD, VALUE)           (CATH_PACK_BITS((WORD), (VALUE), 26, 6))
    #define         SCU_DSP_PACK_SRC_X(WORD, VALUE)             (CATH_PACK_BITS((WORD), (VALUE), 20, 6))
    #define         SCU_DSP_PACK_SRC_Y(WORD, VALUE)             (CATH_PACK_BITS((WORD), (VALUE), 14, 6))
    #define         SCU_DSP_PACK_DESTINATION(WORD, VALUE)       (CATH_PACK_BITS((WORD), (VALUE), 0, 8))
    #define         SCU_DSP_PACK_ALU(WORD, VALUE)               (CATH_PACK_BITS((WORD), (VALUE), 24, 4))

    /////////////////////////////////////////////////////////
    //                FUNCTION PROTOTYPES
    /////////////////////////////////////////////////////////

    void CATH_DSP_INSTRUCTION_INIT(SH_DSP_INSTRUCTION*, U32, U32);
    void CATH_DSP_INSTRUCTION_PROCESS(SH_DSP_INSTRUCTION*);
    UNK CATH_DSP_INSTRUCTION_DISASM(const SH_DSP_INSTRUCTION*, char*);
    UNK CATH_DSP_INSTRUCTION_DISASM_OPERAND(const SH_DSP_INSTRUCTION*, char*);

    extern const SH_DSP_DESCRIPTOR DSP_DESCRIPTORS[];
    extern const char* CATH_DSP_INSTR_ID_NAMES[];
    extern const char* CATH_GET_DSP_OPCODE_NAME(CATH_INSTR_ID_DSP INSTR_ID);

#ifdef __cplusplus
}
#endif

#endif
#endif
