// COPYRIGHT (C) HARRY CLARK 2026
// HITACHI SUPERH INSTRUCTION DECODER

// THIS FILE PERTAINS TOWARDS THE MODULARISATION AND LAYOUT OF THE INSTRUCTIONS
// IDENTIFIERS, THEIR RESPECTIVE CHARACTERISTICS, THE CONCATENATION OF TYPES
// AND HELPER FUNCTIONS - ALL PERTAINING TOWARDS THE INSTRUCTIONS OF THE SCU DSP 

#ifndef CATH_INSTR_DSP_HPP
#define CATH_INSTR_DSP_HPP

#pragma once

// NESTED INCLUDES

#include "common.h"
#include "util.h"
#include "instructions/instructionDSP.h"
#include "instructions/operandsDSP.h"
#include "instructions/registerDSP.h"

namespace catherine
{
    class CATH_INSTRUCTION_DSP
    {
        protected:
            ::SH_DSP_INSTRUCTION INSTR;
            CATH_INSTRUCTION_DSP() = default;
            virtual ~CATH_INSTRUCTION_DSP() = default;
    };
}

#endif