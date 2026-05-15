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
        SH_DSP_OPERAND_TYPE SRC;
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

    // DEFINE THE BASIS FOR ACCESSING
    // THE PARALLELISED STATE OF THE DSP SLOTS
    // AND THEIR ACTIVITY
    typedef struct SH_DSP_PARALLEL_SLOT
    {
        SH_DSP_OPERAND_TYPE SOURCE;
        const char* MNEMONIC;
        const char* DEST_NAME;
        const char* SRC_NAME;                   // ONLY EVER USED FOR MNEMONIC WITH S,D
        bool IS_ACTIVE;
        bool IS_ALU;

    } SH_DSP_PARALLEL_SLOT;

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

        bool IS_PARALLEL;
        SH_DSP_PARALLEL_SLOT X_SLOT;
        SH_DSP_PARALLEL_SLOT Y_SLOT;
        SH_DSP_PARALLEL_SLOT D_SLOT;

    } SH_DSP_INSTRUCTION;

    // DEFINE THE BASIS FOR AN ENTRY WITHIN THE SLOT TABLE 
    typedef struct SH_DSP_ENTRY
    {
        U32 MASK;
        U32 PATTERN;
        CATH_INSTR_ID_DSP ID;

    } SH_DSP_ENTRY;

    // DEFINE THE BASIS FOR D-BUS ACCESS
    // ONLY EVER USED FOR INSTRUCTIONS WHOSE PATTERNS ARE COMBINATORIAL
    // AND NEED PROPER MEANS OF DISTINGUISHING
    typedef struct SH_DSP_D_OP_ENTRY
    {
        U8 OP_MASK;
        U8 OP_PATTERN;

        const char* MNEMONIC;
        const char* DEST_NAME;

        SH_DSP_OPERAND_TYPE SOURCE;

    } SH_DSP_D_OP_ENTRY;

    // PRE PROCESSOR DIRECTIVES TO HELP WITH ACCESS TO SPECIFIC CHARACTERISTICS CPU-WISE
    // ACCEES TO OPCODE WORD, FUNCTION ID AND CALLBACKS

    #define         SCU_DSP_GET_OPERAND(VALUE)                  (CATH_SHIFT_R((VALUE)->WORD, 26, 6))
    #define         SCU_DSP_GET_END(VALUE)                      (CATH_SHIFT_R((VALUE)->WORD, 15, 1))
    #define         SCU_DSP_GET_EXE(VALUE)                      (CATH_SHIFT_R((VALUE)->WORD, 14, 1))
    #define         SCU_DSP_GET_ALU(VALUE)                      (CATH_SHIFT_R((VALUE)->WORD, 26, 6))

    #define         SCU_DSP_GET_SRC_X(VALUE)                    (CATH_SHIFT_R((VALUE)->WORD, 20, 6))
    #define         SCU_DSP_GET_SRC_Y(VALUE)                    (CATH_SHIFT_R((VALUE)->WORD, 14, 6))
    #define         SCU_DSP_GET_SRC_D(VALUE)                    (CATH_SHIFT_R((VALUE)->WORD, 8, 6))

    #define         SCU_DSP_GET_DESTINATION(VALUE)              (CATH_SHIFT_R((VALUE)->WORD, 0, 8))

    #define         SCU_DSP_GET_IMM(VALUE)                      (CATH_SHIFT_R((VALUE)->WORD, 0, 8))
    #define         SCU_DSP_GET_IMM16(VALUE)                    (CATH_SHIFT_R((VALUE)->WORD, 0, 16))

    #define         SCU_DSP_GET_JUMP_ADDR(VALUE)                (CATH_SHIFT_R((VALUE)->WORD, 0, 8))
    #define         SCU_DSP_GET_COND(VALUE)                     (CATH_SHIFT_R((VALUE)->WORD, 8, 4))

    #define         SCU_DSP_PACK_OPERAND(WORD, VALUE)           (CATH_PACK_BITS((WORD), (VALUE), 26, 6))
    #define         SCU_DSP_PACK_SRC_X(WORD, VALUE)             (CATH_PACK_BITS((WORD), (VALUE), 20, 6))
    #define         SCU_DSP_PACK_SRC_Y(WORD, VALUE)             (CATH_PACK_BITS((WORD), (VALUE), 14, 6))
    #define         SCU_DSP_PACK_DESTINATION(WORD, VALUE)       (CATH_PACK_BITS((WORD), (VALUE), 0, 8))
    #define         SCU_DSP_PACK_ALU(WORD, VALUE)               (CATH_PACK_BITS((WORD), (VALUE), 24, 4))

    // ADDITIONAL PRE PROCESSOR DIRECTIVES TO HELP WITH ACCESS
    // TO SUB-FIELDS FOR PARALLLISED DECODING

    #define         SCU_DSP_GET_X_OP(VALUE)                     (CATH_SHIFT_R((VALUE)->WORD, 23, 3))
    #define         SCU_DSP_GET_X_SRC(VALUE)                    (CATH_SHIFT_R((VALUE)->WORD, 20, 3))

    #define         SCU_DSP_GET_Y_OP(VALUE)                     (CATH_SHIFT_R((VALUE)->WORD, 17, 3))
    #define         SCU_DSP_GET_Y_SRC(VALUE)                    (CATH_SHIFT_R((VALUE)->WORD, 14, 3))

    #define         SCU_DSP_GET_D_OP(VALUE)                     (CATH_SHIFT_R((VALUE)->WORD, 12, 2))
    #define         SCU_DSP_GET_D_DEST(VALUE)                   (CATH_SHIFT_R((VALUE)->WORD, 8, 4))
    #define         SCU_DSP_GET_D_SRC(VALUE)                    (CATH_SHIFT_R((VALUE)->WORD, 0, 4))
    #define         SCU_DSP_GET_D_SIMM(VALUE)                   (CATH_SHIFT_R((VALUE)->WORD, 0, 8))

    #define         SCU_DSP_GET_RAM_BANK(VALUE)                 ((VALUE >> 4) & 0x3)
    #define         SCU_DSP_GET_CT(VALUE)                       ((VALUE >> 2) & 0x3)
    #define         SCU_DSP_ACC_CMP_MASK(VALUE)                 (((VALUE) & 0x01))

    #define         SCU_DSP_SLOT_COUNT(TABLE)                   (sizeof(TABLE) / sizeof(TABLE[0]))
        
    #define         SCU_DSP_D_OP_NOP                            0x00
    #define         SCU_DSP_D_OP_MOV_SIMM                       0x01
    #define         SCU_DSP_D_OP_MOV_SRC                        0x03

    // A DISTINCTION NEEDS TO BE MADE BETWEEN JMP AND MVI
    // WHEN THEIR ENCODING SHARE THE SAME BITS (31:26)

    #define         SCU_DSP_GET_MVI_DEST(VALUE)                 (CATH_SHIFT_R((VALUE)->WORD, 26, 4))
    #define         SCU_DSP_GET_MVI_COND_BIT(VALUE)             (CATH_SHIFT_R((VALUE)->WORD, 25, 1))
    #define         SCU_DSP_GET_MVI_NEGATE(VALUE)               (CATH_SHIFT_R((VALUE)->WORD, 24, 1))
    #define         SCU_DSP_GET_MVI_STATUS(VALUE)               (CATH_SHIFT_R((VALUE)->WORD, 19, 5))
    #define         SCU_DSP_GET_MVI_IMM_COND(VALUE)             (CATH_SHIFT_R((VALUE)->WORD,  0, 19))
    #define         SCU_DSP_GET_MVI_IMM_UNCOND(VALUE)           (CATH_SHIFT_R((VALUE)->WORD,  0, 25))

    // EVALUATIVE MACROS FOR ACCESSING THE CORRESPONDENCE FOR THE 
    // DMA CHANNELS
    // 
    // WITH DUE REGARD FOR THE SPECIFIC MODES AND CONDITIONS ENCOMPASSING SUCH

    #define         SCU_DSP_GET_DMA_CHANNEL(VALUE)              (CATH_SHIFT_R((VALUE)->WORD, 12, 1))
    #define         SCU_DSP_GET_DMA_RAM(VALUE)                  (CATH_SHIFT_R((VALUE)->WORD, 8, 2))
    #define         SCU_DSP_GET_DMA_ADD_MODE(VALUE)             (CATH_SHIFT_R((VALUE)->WORD, 15, 3))
    #define         SCU_DSP_GET_DMA_COUNT(VALUE)                (CATH_SHIFT_R((VALUE)->WORD, 0, 8))

    #define         SCU_DSP_IS_MVI(VALUE)                                   \
            ((CATH_SHIFT_R((VALUE)->WORD, 30, 2)) == 0x2)

    #define         SCU_DSP_IS_DMA(VALUE)                                   \
            (((VALUE)->WORD & 0xF0007C00) == 0xC0000000                     \
            && ((VALUE)->WORD & 0x00010000))

    #define         SCU_DSP_MVI_COND_MAX                        0x09

    // DEFINED ACCESS MASK VALUES FOR DETERMING THE CONTROL FLOW
    // OVER PARALLELISED INSTRUCTION FORMATS FOR COMBINATORIAL INSTRUCTIONS

    #define             SCU_DSP_END_MASK                    0x01
    #define             SCU_DSP_ENDI_MASK                   0x02
    #define             SCU_DSP_LOOP_MASK                   0x10
    #define             SCU_DSP_BTM_MASK                    0x11
    #define             SCU_DSP_LPS_MASK                    0x12
    #define             SCU_DSP_BF_MASK                     0x18
    #define             SCU_DSP_JMP_MASK                    0x20
    #define             SCU_DSP_MVI_MASK                    0x28
    #define             SCU_DSP_MOV_MASK                    0x30
    #define             SCU_DSP_DMA_MASK                    0x31

    // WHOLE-WORD EVALUATION DESIGNED TO DETECT THE TOP 6 BITS 
    // OF AN IDENTIFIED WORD TO DETERMINE ITS CONTROL FLOW STATE
    #define         SCU_DSP_IS_CONTROL_FLOW(VALUE)                              \
        (SCU_DSP_GET_ALU(VALUE) == SCU_DSP_END_MASK                             \
        || SCU_DSP_GET_ALU(VALUE) == SCU_DSP_ENDI_MASK                          \
        || SCU_DSP_GET_ALU(VALUE) == SCU_DSP_LOOP_MASK                          \
        || SCU_DSP_GET_ALU(VALUE) == SCU_DSP_BTM_MASK                           \
        || SCU_DSP_GET_ALU(VALUE) == SCU_DSP_LPS_MASK                           \
        || SCU_DSP_GET_ALU(VALUE) == SCU_DSP_BF_MASK                            \
        || SCU_DSP_IS_MVI(VALUE)                                                \
        || SCU_DSP_IS_DMA(VALUE)                                                \
        || SCU_DSP_GET_ALU(VALUE) == SCU_DSP_MOV_MASK)                          \

    /////////////////////////////////////////////////////////
    //                FUNCTION PROTOTYPES
    /////////////////////////////////////////////////////////

    void CATH_DSP_INSTRUCTION_INIT(SH_DSP_INSTRUCTION*, U32, U32);
    void CATH_DSP_INSTRUCTION_PROCESS(SH_DSP_INSTRUCTION*);
    UNK CATH_DSP_INSTRUCTION_DISASM(const SH_DSP_INSTRUCTION*, char*);
    UNK CATH_DSP_INSTRUCTION_DISASM_OPERAND(const SH_DSP_INSTRUCTION*, char*);
    UNK CATH_DSP_INSTRUCTION_GET_SIZE(const SH_DSP_INSTRUCTION*);

    extern const SH_DSP_DESCRIPTOR DSP_DESCRIPTORS[];
    extern const char* CATH_DSP_INSTR_ID_NAMES[];
    extern const char* CATH_GET_DSP_OPCODE_NAME(CATH_INSTR_ID_DSP INSTR_ID);

    extern const SH_DSP_ENTRY CATH_DSP_ENTRY_TABLE[];
    extern const UNK CATH_DSP_ENTRY_TABLE_SIZE;

    // ISOLATED DEFINITION OF THE BUS OPERATION TABLES ADJACENT FROM 
    // SOURCE FILE IMPLEMENTATION
    //
    // A NECESSITY BORN OUT OF WANTING TO REDUCE THE AMOUNT OF CLUTTER
    // DELEGATED TO THE API OF THE SOURCE FILES THEMSELVES
    
    #ifdef CATH_USE_BUS_DECODE_TABLE

    static const SH_DSP_D_OP_ENTRY CATH_DSP_X_OP_TABLE[] =
    {
        { .OP_MASK = 0x07, .OP_PATTERN = 0x00, .MNEMONIC = NULL,  .DEST_NAME = NULL, .SOURCE = DSP_OPERAND_NONE },
        { .OP_MASK = 0x04, .OP_PATTERN = 0x04, .MNEMONIC = "MOV", .DEST_NAME = "X",  .SOURCE = DSP_OPERAND_X   },
        { .OP_MASK = 0x07, .OP_PATTERN = 0x02, .MNEMONIC = "MOV", .DEST_NAME = "P",  .SOURCE = DSP_OPERAND_MUL }, 
        { .OP_MASK = 0x07, .OP_PATTERN = 0x03, .MNEMONIC = "MOV", .DEST_NAME = "P",  .SOURCE = DSP_OPERAND_X   }, 
        { .OP_MASK = 0x00, .OP_PATTERN = 0x00, .MNEMONIC = NULL,  .DEST_NAME = NULL, .SOURCE = DSP_OPERAND_NONE },
    };

    static const SH_DSP_D_OP_ENTRY CATH_DSP_Y_OP_TABLE[] =
    {
        { .OP_MASK = 0x07, .OP_PATTERN = 0x00, .MNEMONIC = NULL,  .DEST_NAME = NULL, .SOURCE = DSP_OPERAND_NONE },
        { .OP_MASK = 0x04, .OP_PATTERN = 0x04, .MNEMONIC = "MOV", .DEST_NAME = "Y",  .SOURCE = DSP_OPERAND_Y   }, 
        { .OP_MASK = 0x07, .OP_PATTERN = 0x01, .MNEMONIC = "CLR", .DEST_NAME = "A",  .SOURCE = DSP_OPERAND_NONE }, 
        { .OP_MASK = 0x07, .OP_PATTERN = 0x02, .MNEMONIC = "MOV", .DEST_NAME = "A",  .SOURCE = DSP_OPERAND_ALU }, 
        { .OP_MASK = 0x07, .OP_PATTERN = 0x03, .MNEMONIC = "MOV", .DEST_NAME = "A",  .SOURCE = DSP_OPERAND_Y   },
        { .OP_MASK = 0x00, .OP_PATTERN = 0x00, .MNEMONIC = NULL,  .DEST_NAME = NULL, .SOURCE = DSP_OPERAND_NONE },
    };

    static const SH_DSP_D_OP_ENTRY CATH_DSP_D_OP_TABLE[] =
    {
        { .OP_MASK = 0x03, .OP_PATTERN = 0x00, .MNEMONIC = NULL,  .DEST_NAME = NULL,  .SOURCE = DSP_OPERAND_NONE },
        { .OP_MASK = 0x03, .OP_PATTERN = 0x01, .MNEMONIC = "MOV", .DEST_NAME = NULL,  .SOURCE = DSP_OPERAND_IMM  },
        { .OP_MASK = 0x03, .OP_PATTERN = 0x03, .MNEMONIC = "MOV", .DEST_NAME = NULL,  .SOURCE = DSP_OPERAND_STORE},
        { .OP_MASK = 0x00, .OP_PATTERN = 0x00, .MNEMONIC = NULL,  .DEST_NAME = NULL,  .SOURCE = DSP_OPERAND_NONE },
    };

    #endif

#ifdef __cplusplus
}
#endif

#endif
#endif
