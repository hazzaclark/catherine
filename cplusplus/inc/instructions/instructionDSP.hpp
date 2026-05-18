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
#include "enums/instructionsDSP.hpp"

namespace catherine
{
    class CATH_INSTRUCTION_DSP
    {
        protected:
            ::SH_DSP_INSTRUCTION INSTR;

            CATH_INSTRUCTION_DSP() = default;
            virtual ~CATH_INSTRUCTION_DSP() = default;

        public:
            // ACCESS THE RAW POINTER FOR THE INSTRUCTION
            // WE CAN REFERENCE - NOT SURE IF THIS WILL BE NEEDED THOUGH
            // I AM JUST LEVERAGING THE SAME DESIGN AS BEFORE
            const SH_DSP_INSTRUCTION* CATH_DSP_GET_RAW_PTR() const;

            // ACCESS THE UNIQUE INSTRUCTION MUCH SIMILAR TO THE 
            // DESIGN OF INSTRUCTION.HPP
            inline INSTR_ID_DSP::CATH_INSTR_ID_DSP_CXX CATH_DSP_GET_UNIQUE_ID() const
            {
                return static_cast<INSTR_ID_DSP::CATH_INSTR_ID_DSP_CXX>(this->INSTR.INSTR_ID);
            }
    };
}

#endif
