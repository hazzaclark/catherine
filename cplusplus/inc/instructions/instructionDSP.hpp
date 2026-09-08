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
#include "cath_utils.h"
#include "instructions/instructionDSP.h"
#include "instructions/operandsDSP.h"
#include "instructions/registerDSP.h"
#include "enums/instructionsDSP.hpp"

// SYSTEM INCLUDES

#include <array>

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

            // ACCESS THE UNIQUE INSTRUCTION DESCRIPTOR BY READING OPERAND ROLES
            // AND CATEGORY FLAGS WITHOUT GOING THROUGH THE RAW POINTER
            //
            // OTHER FIELDS REMAIN HERE FOR THE SAKE OF DOCUMENTATION
            inline const SH_DSP_DESCRIPTOR* CATH_DSP_GET_DESCRIPTOR() const
            {
                return this->INSTR.DESCRIPTOR;
            }

            // ACCESS DIRECTLY THE METHODS AND THE FIELDS ENCOMPASSING THE DSP OPCODE'S
            // RAW WORD, ITS ADDRESS, AND THE FORMAT OF THE INSTRUCTION (PARALLEL OR COMBINATORIAL)
            
            inline U32 CATH_DSP_GET_WORD() const { return this->INSTR.WORD; }
            inline U32 CATH_DSP_GET_PC() const { return this->INSTR.PC; }
            inline bool CATH_DSP_IS_PARALLEL() const { return this->INSTR.IS_PARALLEL; }

            // ACCESS THE SLOTS THAT ENCOMPASS A COMMON DSP INSTRUCTION
            inline std::array<const SH_DSP_PARALLEL_SLOT*, SCU_DSP_SLOT_COUNT> CATH_DSP_GET_SLOTS() const
            {
                return { &this->INSTR.XP_SLOT, &this->INSTR.X_SLOT, &this->INSTR.YA_SLOT,
                    &this->INSTR.Y_SLOT, &this->INSTR.D_SLOT };
            }

            // ACCESS ALL OF THE CONTENTS OF THE RESPECTIVE FIELD
            // LEVERAGE CONSTEXPR FOR COMPILE TIME EVALUATION

            static constexpr U8 CATH_DSP_GET_OPCODE(U32 WORD) { return static_cast<U8>(CATH_SHIFT_R(WORD, 26, 6)); }
            static constexpr U8 CATH_DSP_GET_END(U32 WORD) { return static_cast<U8>(CATH_SHIFT_R(WORD, 15, 1)); }
            
            std::string CATH_DSP_DISASSEMBLE_OPERANDS() const;
            std::string CATH_DSP_DISASSEMBLE_INSTR() const;
            std::string CATH_DSP_DISASSEMBLE_DATA() const;
            std::string CATH_DSP_DISASSMBLE() const; 
    };

    // ABSTRACTED METHOD ALL FOR THE PURPOSE OF INNATE INSTRUCTION 
    // ACCESS BASED ON THE CHARACTERISTICS OF THE ABOVE CLASS

    class CATH_INSTRUCTION_SCU_DSP : public CATH_INSTRUCTION_DSP
    {
        public:
            CATH_INSTRUCTION_SCU_DSP(U32 WORD, U32 ADDRESS);
            virtual ~CATH_INSTRUCTION_SCU_DSP() = default;
    };
}

#endif
