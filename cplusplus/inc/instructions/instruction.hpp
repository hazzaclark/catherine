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
            CATH_INSTRUCTION(U16, U32) noexcept;
            virtual ~CATH_INSTRUCTION() = default;
        
        public:

            // ACCESS THE RAW POINTER FOR THE INSTRUCTION
            // WE CAN REFERENCE ACCORDINGLY
            SH_INSTRUCTION* CATH_GET_RAW_PTR();

            // THE FOLLOWING METHODS SERVE TO ACT AS
            // GENERAL GETTERS AND SETTERS WHICH ACCESS
            // THE API FEATURES AND JUST REWORK THEM 
            // FOR THIS CONTEXT

            U8 CATH_GET_OPCODE4() const;
            U8 CATH_GET_OPCODE8() const;
            U8 CATH_GET_OPCODE12() const;

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

            CATH_GPR CATH_GET_RN_REG() const;
            CATH_GPR CATH_GET_RM_REG() const;
            CATH_CTRL CATH_GET_CTRL_REG() const;
            CATH_SYS CATH_GET_SYS_REG() const;

            void CATH_SET_IMM8(U8 VAL);
            void CATH_SET_DISP8(U8 VAL);
            void CATH_SET_DISP12(U8 VAL);

            void CATH_SET_RN_REG(CATH_GPR REG);
            void CATH_SET_RM_REG(CATH_GPR REG);
            void CATH_SET_CTRL_REG(CATH_CTRL REG);
            void CATH_SET_SYS_REG(CATH_SYS REG);

            // THESE GETTERS WILL ACCESS THE CHANGED VALUES
            // PROVIDED FOR A GIVEN PROCESSED VALUE
            // ONLY EVER ACCESSED DURING FUNCTION CALL RUNTIMES
            
            S32 CATH_GET_PROC_IMM() const;
            S32 CATH_GET_PROC_DISP() const;
            S32 CATH_GET_BRA_TARGET() const;

            inline U16 CATH_GET_RAW_INSTR() const { return CATH_GET_RAW(&INSTR); }
            inline U32 CATH_GET_RAW_PC() const { return CATH_GET_PC(&INSTR); }
            inline S32 CATH_GET_BRA_OFFSET() const { return CATH_GET_BRANCH_OFFSET(&INSTR); }

            // ACCESS THE CONTENTS OF THE REGISTERS SAFELY THROUGH
            // THEIR RESPECTIVE ACCESS METHOD
            static constexpr U16 CATH_SET_RN(U16 WORD, U16 VALUE)
            {
                return (WORD & static_cast<U16>(~(0xF << 8))) 
                | static_cast<U16>((VALUE & 0xF) << 8);
            }

            static constexpr U16 CATH_SET_RM(U16 WORD, U16 VALUE)
            {
                return (WORD & static_cast<U16>(~(0xF << 4))) 
                | static_cast<U16>((VALUE & 0xF) << 4);
            }
    };

    // INLINE IMPLEMENTATIONS ACCESSING RAW POINTERS
    // FROM THE BASELINE API
    inline SH_INSTRUCTION* CATH_INSTRUCTION::CATH_GET_RAW_PTR()
    {
        return &INSTR;
    }
}

#endif

