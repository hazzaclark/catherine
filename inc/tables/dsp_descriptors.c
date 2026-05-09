// COPYRIGHT (C) HARRY CLARK 2025
// HITACHI SUPERH INSTRUCTION DECODER

// THIS FILE PERTAINS TOWARDS THE DESCRIPTORS FOR EACH INSTRUCTION TYPE
// SPECIFICALLY FOCUSSED ON THE DSP

// NESTED INCLUDES

#include "instructions/instructionDSP.h"

// THE INTRINSIC VALUE OF THE DSP ITSELF IS THAT RATHER THAN ACCOUNTING 
// FOR THE STATIC AND DETERMINISTIC RESULTS OF INSTRUCTION CHARACTERISTICS
// THE DSP LEVERAGES A PARALLELISED APPROACH
//
// EACH OF THE FOLLOWING DESCRIPTORS AGAINST THEIR RESPECTIVE ENUM VALUE
// WILL PROVIDE A TEMPLATE OF SORTS - WHICH WILL BE EVALUATED AT RUNTIME
// BASED ON THEIR RESPECTIVE VALUE WITHIN DATA RAM

const SH_DSP_DESCRIPTOR DSP_DESCRIPTORS[CATH_INSTR_ID_DSP_ALL_MAX] = 
{
    [CATH_INSTR_ID_DSP_INVALID] = 
    {
        .X_BUS_SRC = DSP_OPERAND_NONE,
        .Y_BUS_SRC = DSP_OPERAND_NONE,
        .D_BUS_SRC = DSP_OPERAND_NONE,
        .DEST = DSP_OPERAND_NONE,
        .IS_NOP = true,
        .IS_ALU_OP = false,
    },
    
    [CATH_INSTR_ID_DSP_AD2] = 
    {
        .X_BUS_SRC = DSP_OPERAND_X,
        .Y_BUS_SRC = DSP_OPERAND_Y,
        .D_BUS_SRC = DSP_OPERAND_ALU,
        .DEST = DSP_OPERAND_ACC,
        .IS_ALU_OP = true,
        .IS_MOVE = false,
        .X_BUS = 1,
        .Y_BUS = 1,
        .D_BUS = 1,
        .WRITE_DEST = 0,
    },
    
    [CATH_INSTR_ID_DSP_ADD] = 
    {
        .X_BUS_SRC = DSP_OPERAND_X,
        .Y_BUS_SRC = DSP_OPERAND_Y,
        .D_BUS_SRC = DSP_OPERAND_ALU,
        .DEST = DSP_OPERAND_ACC,
        .IS_ALU_OP = true,
        .IS_MOVE = false,
        .X_BUS = 1,
        .Y_BUS = 1,
        .D_BUS = 1,
        .WRITE_DEST = 0,
    },
    
    [CATH_INSTR_ID_DSP_AND] = 
    {
        .X_BUS_SRC = DSP_OPERAND_X,
        .Y_BUS_SRC = DSP_OPERAND_Y,
        .D_BUS_SRC = DSP_OPERAND_ALU,
        .DEST = DSP_OPERAND_ACC,
        .IS_ALU_OP = true,
        .X_BUS = 1,
        .Y_BUS = 1,
        .D_BUS = 1,
        .WRITE_DEST = 0,
    },
    
    [CATH_INSTR_ID_DSP_BF] = 
    {
        .X_BUS_SRC = DSP_OPERAND_NONE,
        .Y_BUS_SRC = DSP_OPERAND_NONE,
        .D_BUS_SRC = DSP_OPERAND_NONE,
        .DEST = DSP_OPERAND_PC,
        .IS_JUMP = true,
        .IS_COND = true,
        .WRITE_DEST = 1,
    },
    
    [CATH_INSTR_ID_DSP_BTM] = 
    {
        .X_BUS_SRC = DSP_OPERAND_NONE,
        .Y_BUS_SRC = DSP_OPERAND_NONE,
        .D_BUS_SRC = DSP_OPERAND_NONE,
        .DEST = DSP_OPERAND_NONE,
        .IS_JUMP = true,
        .IS_COND = true,
    },
    
    [CATH_INSTR_ID_DSP_CLR] = 
    {
        .X_BUS_SRC = DSP_OPERAND_NONE,
        .Y_BUS_SRC = DSP_OPERAND_NONE,
        .D_BUS_SRC = DSP_OPERAND_ALU,
        .DEST = DSP_OPERAND_ACC,
        .IS_ALU_OP = true,
        .IS_MOVE = false,
        .X_BUS = 0,
        .Y_BUS = 0,
        .D_BUS = 1,
        .WRITE_DEST = 0,
    },
    
    [CATH_INSTR_ID_DSP_DMA] = 
    {
        .X_BUS_SRC = DSP_OPERAND_NONE,
        .Y_BUS_SRC = DSP_OPERAND_NONE,
        .D_BUS_SRC = DSP_OPERAND_NONE,
        .DEST = DSP_OPERAND_NONE,
        .IS_LOAD_STORE = true,
        .WRITE_DEST = 0,
    },
    
    [CATH_INSTR_ID_DSP_END] = 
    {
        .X_BUS_SRC = DSP_OPERAND_NONE,
        .Y_BUS_SRC = DSP_OPERAND_NONE,
        .D_BUS_SRC = DSP_OPERAND_NONE,
        .DEST = DSP_OPERAND_NONE,
        .IS_END = true,
    },
    
    [CATH_INSTR_ID_DSP_ENDI] = 
    {
        .X_BUS_SRC = DSP_OPERAND_NONE,
        .Y_BUS_SRC = DSP_OPERAND_NONE,
        .D_BUS_SRC = DSP_OPERAND_NONE,
        .DEST = DSP_OPERAND_NONE,
        .IS_END = true,
        .IS_END_JMP = true,
    },
    
    [CATH_INSTR_ID_DSP_JMP] = 
    {
        .X_BUS_SRC = DSP_OPERAND_NONE,
        .Y_BUS_SRC = DSP_OPERAND_NONE,
        .D_BUS_SRC = DSP_OPERAND_NONE,
        .DEST = DSP_OPERAND_PC,
        .IS_JUMP = true,
        .WRITE_DEST = 1,
    },
    
    [CATH_INSTR_ID_DSP_LOOP] = 
    {
        .X_BUS_SRC = DSP_OPERAND_NONE,
        .Y_BUS_SRC = DSP_OPERAND_NONE,
        .D_BUS_SRC = DSP_OPERAND_NONE,
        .DEST = DSP_OPERAND_TOP,
        .IS_LOOP = true,
        .WRITE_DEST = 1,
    },
    
    [CATH_INSTR_ID_DSP_LPS] = 
    {
        .X_BUS_SRC = DSP_OPERAND_NONE,
        .Y_BUS_SRC = DSP_OPERAND_NONE,
        .D_BUS_SRC = DSP_OPERAND_NONE,
        .DEST = DSP_OPERAND_TOP,
        .IS_LOOP = true,
        .WRITE_DEST = 1,
    },
    
    [CATH_INSTR_ID_DSP_MOV] = 
    {
        .X_BUS_SRC = DSP_OPERAND_X,
        .Y_BUS_SRC = DSP_OPERAND_NONE,
        .D_BUS_SRC = DSP_OPERAND_ALU,
        .DEST = DSP_OPERAND_ACC,
        .IS_ALU_OP = false,
        .IS_MULTIPLY = false,
        .IS_MOVE = true,
        .X_BUS = 1,
        .Y_BUS = 0,
        .D_BUS = 1,
        .WRITE_DEST = 0,
    },
    
    [CATH_INSTR_ID_DSP_MUL] = 
    {
        .X_BUS_SRC = DSP_OPERAND_X,
        .Y_BUS_SRC = DSP_OPERAND_Y,
        .D_BUS_SRC = DSP_OPERAND_MUL,
        .DEST = DSP_OPERAND_MUL,
        .IS_ALU_OP = false,
        .IS_MULTIPLY = true,
        .IS_MOVE = false,
        .X_BUS = 1,
        .Y_BUS = 1,
        .D_BUS = 1,
        .WRITE_DEST = 1,
    },
    
    [CATH_INSTR_ID_DSP_MVI] = 
    {
        .X_BUS_SRC = DSP_OPERAND_NONE,
        .Y_BUS_SRC = DSP_OPERAND_NONE,
        .D_BUS_SRC = DSP_OPERAND_IMM,
        .DEST = DSP_OPERAND_IMM,
        .IS_ALU_OP = false,
        .IS_MULTIPLY = false,
        .IS_MOVE = true,
        .X_BUS = 0,
        .Y_BUS = 0,
        .D_BUS = 1,
        .WRITE_DEST = 1,
    },
    
    [CATH_INSTR_ID_DSP_NOP] = 
    {
        .X_BUS_SRC = DSP_OPERAND_NONE,
        .Y_BUS_SRC = DSP_OPERAND_NONE,
        .D_BUS_SRC = DSP_OPERAND_NONE,
        .DEST = DSP_OPERAND_NONE,
        .IS_NOP = true,
    },
    
    [CATH_INSTR_ID_DSP_NOT] = 
    {
        .X_BUS_SRC = DSP_OPERAND_X,
        .Y_BUS_SRC = DSP_OPERAND_NONE,
        .D_BUS_SRC = DSP_OPERAND_ALU,
        .DEST = DSP_OPERAND_ACC,
        .IS_ALU_OP = true,
        .IS_MULTIPLY = false,
        .X_BUS = 1,
        .Y_BUS = 0,
        .D_BUS = 1,
        .WRITE_DEST = 0,
    },
    
    [CATH_INSTR_ID_DSP_OR] = 
    {
        .X_BUS_SRC = DSP_OPERAND_X,
        .Y_BUS_SRC = DSP_OPERAND_Y,
        .D_BUS_SRC = DSP_OPERAND_ALU,
        .DEST = DSP_OPERAND_ACC,
        .IS_ALU_OP = true,
        .IS_MOVE = false,
        .X_BUS = 1,
        .Y_BUS = 1,
        .D_BUS = 1,
        .WRITE_DEST = 0,
    },
    
    [CATH_INSTR_ID_DSP_RL] = 
    {
        .X_BUS_SRC = DSP_OPERAND_X,
        .Y_BUS_SRC = DSP_OPERAND_NONE,
        .D_BUS_SRC = DSP_OPERAND_ALU,
        .DEST = DSP_OPERAND_ACC,
        .IS_ALU_OP = true,
        .IS_MOVE = false,
        .X_BUS = 1,
        .Y_BUS = 0,
        .D_BUS = 1,
        .WRITE_DEST = 0,
    },
    
    [CATH_INSTR_ID_DSP_RR] = 
    {
        .X_BUS_SRC = DSP_OPERAND_X,
        .Y_BUS_SRC = DSP_OPERAND_NONE,
        .D_BUS_SRC = DSP_OPERAND_ALU,
        .DEST = DSP_OPERAND_ACC,
        .IS_ALU_OP = true,
        .IS_MOVE = false,
        .X_BUS = 1,
        .Y_BUS = 0,
        .D_BUS = 1,
        .WRITE_DEST = 0,
    },
    
    [CATH_INSTR_ID_DSP_SL] = 
    {
        .X_BUS_SRC = DSP_OPERAND_X,
        .Y_BUS_SRC = DSP_OPERAND_NONE,
        .D_BUS_SRC = DSP_OPERAND_ALU,
        .DEST = DSP_OPERAND_ACC,
        .IS_ALU_OP = true,
        .IS_MOVE = false,
        .X_BUS = 1,
        .Y_BUS = 0,
        .D_BUS = 1,
        .WRITE_DEST = 0,
    },
    
    [CATH_INSTR_ID_DSP_SR] = 
    {
        .X_BUS_SRC = DSP_OPERAND_X,
        .Y_BUS_SRC = DSP_OPERAND_NONE,
        .D_BUS_SRC = DSP_OPERAND_ALU,
        .DEST = DSP_OPERAND_ACC,
        .IS_ALU_OP = true,
        .IS_MOVE = false,
        .X_BUS = 1,
        .Y_BUS = 0,
        .D_BUS = 1,
        .WRITE_DEST = 0,
    },
    
    [CATH_INSTR_ID_DSP_SUB] = 
    {
        .X_BUS_SRC = DSP_OPERAND_X,
        .Y_BUS_SRC = DSP_OPERAND_Y,
        .D_BUS_SRC = DSP_OPERAND_ALU,
        .DEST = DSP_OPERAND_ACC,
        .IS_ALU_OP = true,
        .IS_MOVE = false,
        .X_BUS = 1,
        .Y_BUS = 1,
        .D_BUS = 1,
        .WRITE_DEST = 0,
    },
    
    [CATH_INSTR_ID_DSP_XOR] = 
    {
        .X_BUS_SRC = DSP_OPERAND_X,
        .Y_BUS_SRC = DSP_OPERAND_Y,
        .D_BUS_SRC = DSP_OPERAND_ALU,
        .DEST = DSP_OPERAND_ACC,
        .IS_ALU_OP = true,
        .IS_MOVE = false,
        .X_BUS = 1,
        .Y_BUS = 1,
        .D_BUS = 1,
        .WRITE_DEST = 0,
    },
};
