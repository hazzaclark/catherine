// COPYRIGHT (C) HARRY CLARK 2025
// HITACHI SUPERH INSTRUCTION DECODER

// THIS FILE PERTAINS TOWARDS THE DESCRIPTORS FOR EACH INSTRUCTION TYPE

// NESTED INCLUDES

#include "instructions/instruction.h"

const SH_DESCRIPTOR INSTR_DESCRIPTORS[] = 
{
    [CATH_INSTR_ID_INVALID] = 
    {
        .OPERAND_TYPE = {OPERAND_NONE}, .IS_BRANCH = false, 
        .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
        .IS_TRAP = false, .IS_HALT = false,
        .IS_FLOAT = false, .IS_UNSIGNED = false
    },

    [CATH_INSTR_ID_ADD] = 
    {
        .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
        .IS_BRANCH = false,.IS_JUMP = false,
        .IS_JUMP_ADDRESS = false, .IS_TRAP = false,
        .IS_HALT = false, .HAS_DELAY_SLOT = false,
        .IS_FLOAT = false, .IS_UNSIGNED = false,
    },

    [CATH_INSTR_ID_ADDI] =
    {
        .OPERAND_TYPE = {OPERAND_IMM, OPERAND_RN, OPERAND_NONE},
        .IS_BRANCH = false, .IS_JUMP = false,
        .IS_JUMP_ADDRESS = false, .IS_TRAP = false,
        .IS_HALT = false, .HAS_DELAY_SLOT = false,
        .IS_FLOAT = false, .IS_UNSIGNED = false,
    },
};
