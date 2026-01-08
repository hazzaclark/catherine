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
#include "enums/instructions.hpp"

// SYSTEM INCLUDES

#include <string>

namespace catherine
{
    class CATH_INSTRUCTION
    {
        protected:
            ::SH_INSTRUCTION INSTR;

            CATH_INSTRUCTION() = default;
            virtual ~CATH_INSTRUCTION() = default;
        
        public:
            // ACCESS THE RAW POINTER FOR THE INSTRUCTION
            // WE CAN REFERENCE ACCORDINGLY
            SH_INSTRUCTION* CATH_GET_RAW_PTR();

            // GET UNIQUE INSTRUCTION ID
            inline CATH_INSTR_ID_CXX CATH_GET_UNIQUE_ID() const
            {
                return static_cast<CATH_INSTR_ID_CXX>(this->INSTR.INSTR_ID);
            }

            // THE FOLLOWING METHODS SERVE TO ACT AS
            // GENERAL GETTERS AND SETTERS WHICH ACCESS
            // THE API FEATURES AND JUST REWORK THEM 
            // FOR THIS CONTEXT

            CATH_GPR CATH_GET_RN_REG() const;
            CATH_GPR CATH_GET_RM_REG() const;
            CATH_CTRL CATH_GET_CTRL_REG() const;
            CATH_SYS CATH_GET_SYS_REG() const;
            void CATH_SET_RN_REG(CATH_GPR REG);
            void CATH_SET_RM_REG(CATH_GPR REG);
            void CATH_SET_CTRL_REG(CATH_CTRL REG);
            void CATH_SET_SYS_REG(CATH_SYS REG);

            void CATH_SET_IMM8(U8 VAL);
            void CATH_SET_DISP8(U8 VAL);
            void CATH_SET_DISP12(U8 VAL);

            // THESE GETTERS WILL ACCESS THE CHANGED VALUES
            // PROVIDED FOR A GIVEN PROCESSED VALUE
            // ONLY EVER ACCESSED DURING FUNCTION CALL RUNTIMES
            
            S32 CATH_GET_PROC_IMM() const;
            S32 CATH_GET_PROC_DISP() const;
            S32 CATH_GET_BRA_TARGET() const;

            inline U16 CATH_GET_RAW_INSTR() const { return CATH_GET_RAW(&INSTR); }
            inline U32 CATH_GET_RAW_PC() const { return CATH_GET_PC(&INSTR); }
            inline S32 CATH_GET_BRA_OFFSET() const { return CATH_GET_BRANCH_OFFSET(&INSTR); }

            // ACCESS ALL OF THE CONTENTS OF THE RESPECTIVE FIELD
            // LEVERAGE CONSTEXPR FOR COMPILE TIME EVALUATION
            static constexpr U8 CATH_GET_OPCODE4(U16 WORD)
            {
                return static_cast<U8>((WORD >> 12) & 0xF);
            }

            static constexpr U8 CATH_GET_OPCODE8(U16 WORD)
            {
                return static_cast<U8>((WORD >> 8) & 0xFF);
            }

            static constexpr U8 CATH_GET_OPCODE12(U16 WORD)
            {
                return static_cast<U8>((WORD >> 4) & 0xFFF);
            }

            // ACCESS THE CONTENTS OF THE REGISTERS SAFELY THROUGH
            // THEIR RESPECTIVE ACCESS METHOD
            static constexpr U8 CATH_GET_RN(U16 WORD)
            {
                return static_cast<U8>((WORD >> 8) & 0xF);
            }

            static constexpr U8 CATH_GET_RM(U16 WORD)
            {
                return static_cast<U8>((WORD >> 4) & 0xF);
            }

            static constexpr U8 CATH_GET_IMM4(U16 WORD)
            {
                return static_cast<U8>(WORD & 0xF);
            }

            static constexpr U8 CATH_GET_IMM8(U16 WORD)
            {
                return static_cast<U8>(WORD & 0xFF);
            }

            static constexpr U8 CATH_GET_DISP4(U16 WORD)
            {
                return static_cast<U8>(WORD & 0xF);
            }

            static constexpr U8 CATH_GET_DISP8(U16 WORD)
            {
                return static_cast<U8>(WORD & 0xFF);
            }

            static constexpr U16 CATH_GET_DISP12(U16 WORD)
            {
                return static_cast<U16>(WORD & 0xFFF);
            }

            static constexpr U8 CATH_GET_CACHE(U16 WORD)
            {
                return static_cast<U8>(WORD & 0xFF);
            }

            static constexpr U8 CATH_GET_MAC(U16 WORD)
            {
                return static_cast<U8>((WORD >> 1) & 0x1);
            }

            static constexpr U8 CATH_GET_IMASK(U16 WORD)
            {
                return static_cast<U8>((WORD >> 4) & 0xF);
            }

            static constexpr U8 CATH_GET_GBR_DISP(U16 WORD)
            {
                return static_cast<U8>(WORD & 0xFF);
            }

            static constexpr U8 CATH_GET_PC_DISP(U16 WORD)
            {
                return static_cast<U8>(WORD & 0xFF);
            }

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

            static constexpr U16 CATH_SET_IMM4(U16 WORD, U8 VALUE)
            {
                return (WORD & static_cast<U16>(~0xF)) 
                     | static_cast<U16>(VALUE & 0xF);
            }

            static constexpr U16 CATH_SET_IMM8(U16 WORD, U8 VALUE)
            {
                return (WORD & static_cast<U16>(~0xFF)) 
                     | static_cast<U16>(VALUE);
            }

            static constexpr U16 CATH_SET_DISP8(U16 WORD, U8 VALUE)
            {
                return (WORD & static_cast<U16>(~0xFF)) 
                     | static_cast<U16>(VALUE);
            }

            static constexpr U16 CATH_SET_DISP12(U16 WORD, U16 VALUE)
            {
                return (WORD & static_cast<U16>(~0xFFF)) 
                     | static_cast<U16>(VALUE & 0xFFF);
            }

            // MEMBER DECLARATIONS TO ACCESS CONSTEXPR'S
            inline U8 CATH_GET_OPCODE4() const { return CATH_GET_OPCODE4(INSTR.WORD); }
            inline U8 CATH_GET_OPCODE8() const { return CATH_GET_OPCODE8(INSTR.WORD); }
            inline U8 CATH_GET_OPCODE12() const { return CATH_GET_OPCODE12(INSTR.WORD); }
            inline U8 CATH_GET_RN() const { return CATH_GET_RN(INSTR.WORD); }
            inline U8 CATH_GET_RM() const { return CATH_GET_RM(INSTR.WORD); }
            inline U8 CATH_GET_IMM4() const { return CATH_GET_IMM4(INSTR.WORD); }
            inline U8 CATH_GET_IMM8() const { return CATH_GET_IMM8(INSTR.WORD); }
            inline U8 CATH_GET_DISP4() const { return CATH_GET_DISP4(INSTR.WORD); }
            inline U8 CATH_GET_DISP8() const { return CATH_GET_DISP8(INSTR.WORD); }
            inline U16 CATH_GET_DISP12() const { return CATH_GET_DISP12(INSTR.WORD); }
            inline U8 CATH_GET_CACHE() const { return CATH_GET_CACHE(INSTR.WORD); }
            inline U8 CATH_GET_MAC() const { return CATH_GET_MAC(INSTR.WORD); }
            inline U8 CATH_GET_IMASK() const { return CATH_GET_IMASK(INSTR.WORD); }
            inline U8 CATH_GET_GBR_DISP() const { return CATH_GET_GBR_DISP(INSTR.WORD); }
            inline U8 CATH_GET_PC_DISP() const { return CATH_GET_PC_DISP(INSTR.WORD); }

            std::string CATH_DISASSEMBLE_OPERANDS() const;
            std::string CATH_DISASSEMBLE_INSTR() const;
            std::string CATH_DISASSEMBLE_DATA() const;
            std::string CATH_DISASSEMBLE() const;
    };

    // INLINE IMPLEMENTATIONS ACCESSING RAW POINTERS
    // FROM THE BASELINE API
    inline SH_INSTRUCTION* CATH_INSTRUCTION::CATH_GET_RAW_PTR()
    {
        return &INSTR;
    }
}

#endif

