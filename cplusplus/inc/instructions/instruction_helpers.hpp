// COPYRIGHT (C) HARRY CLARK 2025
// HITACHI SUPERH INSTRUCTION DECODER

// THIS FILE PERTAINS TOWARDS THE MODULARISATION AND LAYOUT OF THE INSTRUCTIONS
// IDENTIFIERS, THEIR RESPECTIVE CHARACTERISTICS, THE CONCATENATION OF TYPES
// AND HELPER FUNCTIONS
//
// MORE SPECIFICALLY, THIS FILE FOCUSSES ON THE INLINED HELPER FUNCTIONS

#ifndef CATH_INSTR_HELPER_HPP
#define CATH_INSTR_HELPER_HPP

#pragma once

// NESTED INCLUDES

#include "instructions/instruction.hpp"

namespace catherine
{
    #define         CATH_BITMASK_WORD           0xF

    class CATH_INSTRUCTION_HELPER : public CATH_INSTRUCTION
    {
        public:
            inline U16 CATH_GET_RAW_INSTR() const { return CATH_GET_RAW(&INSTR); }
            inline U32 CATH_GET_RAW_PC() const { return CATH_GET_PC(&INSTR); }
            inline S32 CATH_GET_BRA_OFFSET() const { return CATH_GET_BRANCH_OFFSET(&INSTR); }
    };

    namespace helpers
    {
        // ACCESS THE CONTENTS OF THE REGISTERS SAFELY THROUGH
        // THEIR RESPECTIVE ACCESS METHOD
        static constexpr U16 CATH_SET_RN(U16 WORD, U16 VALUE)
        {
            return (WORD & static_cast<U16>(~(CATH_BITMASK_WORD << 8))) 
            | static_cast<U16>((VALUE & CATH_BITMASK_WORD) << 8);
        }

        static constexpr U16 CATH_SET_Rm(U16 WORD, U16 VALUE)
        {
            return (WORD & static_cast<U16>(~(CATH_BITMASK_WORD << 4))) 
            | static_cast<U16>((VALUE & CATH_BITMASK_WORD) << 4);
        }
    }
}

#endif
