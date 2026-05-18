// COPYRIGHT (C) HARRY CLARK 2026
// HITACHI SUPERH INSTRUCTION DECODER

// THIS FILE PERTAINS TOWARDS THE MODULARISATION AND LAYOUT OF THE INSTRUCTIONS
// IDENTIFIERS, THEIR RESPECTIVE CHARACTERISTICS, THE CONCATENATION OF TYPES
// AND HELPER FUNCTIONS - ALL PERTAINING TOWARDS THE INSTRUCTIONS OF THE DSP

#ifndef CATH_INSTR_DSP_ENUM_HPP
#define CATH_INSTR_DSP_ENUM_HPP

#pragma once

// NESTED INCLUDES

#include "instructions/instructionDSP.h"
#include "instructions/operandsDSP.h"
#include "instructions/registerDSP.h"
#include "enums/instructions.h"
#include "enums/category.h"
#include "enums/registerDSP.h"

// SYSTEM INCLUDES

#include <string>

namespace catherine
{
    namespace INSTR_ID_DSP
    {
        enum class CATH_INSTR_ID_DSP_CXX
        {
            CATH_INSTR_ID_DSP_INVALID,
            CATH_INSTR_ID_DSP_AD2,
            CATH_INSTR_ID_DSP_ADD,
            CATH_INSTR_ID_DSP_AND,
            CATH_INSTR_ID_DSP_BF,
            CATH_INSTR_ID_DSP_BTM,
            CATH_INSTR_ID_DSP_CLR,
            CATH_INSTR_ID_DSP_DMA,
            CATH_INSTR_ID_DSP_END,
            CATH_INSTR_ID_DSP_ENDI,
            CATH_INSTR_ID_DSP_LPS,
            CATH_INSTR_ID_DSP_LOOP,
            CATH_INSTR_ID_DSP_JMP,
            CATH_INSTR_ID_DSP_MOV,
            CATH_INSTR_ID_DSP_MUL,
            CATH_INSTR_ID_DSP_MVI,
            CATH_INSTR_ID_DSP_NOP,
            CATH_INSTR_ID_DSP_NOT,
            CATH_INSTR_ID_DSP_OR,
            CATH_INSTR_ID_DSP_RL,
            CATH_INSTR_ID_DSP_RL8,
            CATH_INSTR_ID_DSP_RR,
            CATH_INSTR_ID_DSP_SL,
            CATH_INSTR_ID_DSP_SR,
            CATH_INSTR_ID_DSP_SUB,
            CATH_INSTR_ID_DSP_XOR,
            CATH_INSTR_ID_DSP_ALL_MAX
        };

        // ACCESS THE PROVIDED OPCODE NAME IN CONJUNCTION WITH THE PROVIDED API
        // AS PER INSTRUCTION.HPP, CAST ACCORDINGLY TO ACCESS
        STATIC INLINE 
        std::string CATH_GET_DSP_OPCODE_NAME_CXX(CATH_INSTR_ID_DSP UNIQUE)
        {
            CATH_INSTR_ID_DSP ID = static_cast<CATH_INSTR_ID_DSP>(UNIQUE);
            return std::string(CATH_GET_DSP_OPCODE_NAME(ID));
        }        
    }
}

#endif