// COPYRIGHT (C) HARRY CLARK 2025
// HITACHI SUPERH INSTRUCTION DECODER

// THIS FILE PERTAINS TOWARDS THE MODULARISATION AND LAYOUT OF THE INSTRUCTIONS
// IDENTIFIERS, THEIR RESPECTIVE CHARACTERISTICS, THE CONCATENATION OF TYPES
// AND HELPER FUNCTIONS - ALL PERTAINING TOWARDS THE INSTRUCTIONS

#ifndef CATH_INSTR_HPP
#define CATH_INSTR_HPP

#pragma once

// NESTED INCLUDES

#include "common.h"
#include "util.h"
#include "instructions/instruction.h"
#include "instructions/operands.h"
#include "enums/category.h"
#include "enums/instructions.h"
#include "enums/register.h"

namespace catherine
{
    class CATH_INSTRUCTION
    {
        protected:
            SH_INSTRUCTION INSTR;

            CATH_INSTRUCTION() = default;
            virtual ~CATH_INSTRUCTION() = default;
        
        public:
            // THE FOLLOWING METHODS SERVE TO ACT AS
            // GENERAL GETTERS AND SETTERS WHICH ACCESS
            // THE API FEATURES AND JUST REWORK THEM 
            // FOR THIS CONTEXT

            U8 CATH_GET_OPCODE4() const;
            U8 CATH_GET_OPCODE8() const;
            U8 CATH_GET_OPCODE12() const;

            U8 CATH_GET_RN() const;
            U8 CATH_GET_RM() const;

            U8 CATH_GET_IMM4() const;
            U8 CATH_GET_IMM8() const;
            
            U8 CATH_GET_DISP4() const;
            U8 CATH_GET_DISP8() const;
            U8 CATH_GET_DISP12() const;

            U8 CATH_GET_CACHE() const;
            U8 CATH_GET_MAC() const;
            U8 CATH_GET_IMASK() const;

            U8 CATH_GET_GBR_DISP() const;
            U8 CATH_GET_PC_DISP() const;
    };
}

#endif
