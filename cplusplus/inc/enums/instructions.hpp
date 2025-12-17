// COPYRIGHT (C) HARRY CLARK 2025
// HITACHI SUPERH INSTRUCTION DECODER

// THIS FILE PERTAINS TOWARDS THE MODULARISATION AND LAYOUT OF THE INSTRUCTIONS
// IDENTIFIERS, THEIR RESPECTIVE CHARACTERISTICS, THE CONCATENATION OF TYPES
// AND HELPER FUNCTIONS - ALL PERTAINING TOWARDS THE INSTRUCTIONS

#ifndef CATH_INSTR_ENUM_HPP
#define CATH_INSTR_ENUM_HPP

#pragma once 

// SYSTEM INCLUDES

#include <string>

namespace catherine
{
    namespace INSTR_ID
    {
        enum class CATH_INSTR_ID_CXX
        {
            CATH_INSTR_ID_INVALID,
            CATH_INSTR_ID_ADD,
            CATH_INSTR_ID_ADDC,
            CATH_INSTR_ID_ADDV,
            CATH_INSTR_ID_ADDI,
            CATH_INSTR_ID_AND,
            CATH_INSTR_ID_ANDI,
            CATH_INSTR_ID_ANDM,
            CATH_INSTR_ID_BF,
            CATH_INSTR_ID_BFS,
            CATH_INSTR_ID_BRA,
            CATH_INSTR_ID_BRAF,
            CATH_INSTR_ID_BSR,
            CATH_INSTR_ID_BSRF,
            CATH_INSTR_ID_BT,
            CATH_INSTR_ID_BTS,
            CATH_INSTR_ID_CLRMAC,
            CATH_INSTR_ID_CLRT,
            CATH_INSTR_ID_CMPEQ,
            CATH_INSTR_ID_CMPGE,
            CATH_INSTR_ID_CMPGT,
            CATH_INSTR_ID_CMPHI,
            CATH_INSTR_ID_CMPHS,
            CATH_INSTR_ID_CMPPL,
            CATH_INSTR_ID_CMPPZ,
            CATH_INSTR_ID_CMPSTR,
            CATH_INSTR_ID_CMPEQI,
            CATH_INSTR_ID_DIV0S,
            CATH_INSTR_ID_DIV0U,
            CATH_INSTR_ID_DIV1,
            CATH_INSTR_ID_DMULS,
            CATH_INSTR_ID_DMULU,
            CATH_INSTR_ID_DT,
            CATH_INSTR_ID_EXTSB,
            CATH_INSTR_ID_EXTSW,
            CATH_INSTR_ID_EXTUB,
            CATH_INSTR_ID_EXTUW,
            CATH_INSTR_ID_JMP,
            CATH_INSTR_ID_JSR,
            CATH_INSTR_ID_LDCSR,
            CATH_INSTR_ID_LDCGBR,
            CATH_INSTR_ID_LDCVBR,
            CATH_INSTR_ID_LDCPISR,
            CATH_INSTR_ID_LDCPIGBR,
            CATH_INSTR_ID_LDCPIVBR,
            CATH_INSTR_ID_LDSMACH,
            CATH_INSTR_ID_LDSMACL,
            CATH_INSTR_ID_LDSPR,
            CATH_INSTR_ID_MACW,
            CATH_INSTR_ID_MACL,
            CATH_INSTR_ID_MOV,
            CATH_INSTR_ID_MOVA,
            CATH_INSTR_ID_MOVT,
            CATH_INSTR_ID_MOVI,
            CATH_INSTR_ID_MOVBL,
            CATH_INSTR_ID_MOVWL,
            CATH_INSTR_ID_MOVLL,
            CATH_INSTR_ID_MOVBP,
            CATH_INSTR_ID_MOVWP,
            CATH_INSTR_ID_MOVLP,
            CATH_INSTR_ID_MOVBL0,
            CATH_INSTR_ID_MOVWL0,
            CATH_INSTR_ID_MOVLL0,
            CATH_INSTR_ID_MOVBLG,
            CATH_INSTR_ID_MOVWLG,
            CATH_INSTR_ID_MOVLLG,
            CATH_INSTR_ID_MOVBL4,
            CATH_INSTR_ID_MOVWL4,
            CATH_INSTR_ID_MOVLL4,
            CATH_INSTR_ID_MOVBLP,
            CATH_INSTR_ID_MOVWLP,
            CATH_INSTR_ID_MOVLLP,
            CATH_INSTR_ID_MOVBS,
            CATH_INSTR_ID_MOVWS,
            CATH_INSTR_ID_MOVLS,
            CATH_INSTR_ID_MOVBM,
            CATH_INSTR_ID_MOVWM,
            CATH_INSTR_ID_MOVLM,
            CATH_INSTR_ID_MOVBS0,
            CATH_INSTR_ID_MOVWS0,
            CATH_INSTR_ID_MOVLS0,
            CATH_INSTR_ID_MOVBSG,
            CATH_INSTR_ID_MOVWSG,
            CATH_INSTR_ID_MOVLSG,
            CATH_INSTR_ID_MOVBS4,
            CATH_INSTR_ID_MOVWS4,
            CATH_INSTR_ID_MOVLS4,
            CATH_INSTR_ID_MUL,
            CATH_INSTR_ID_MULU,
            CATH_INSTR_ID_MULS,
            CATH_INSTR_ID_NEG,
            CATH_INSTR_ID_NEGC,
            CATH_INSTR_ID_NOP,
            CATH_INSTR_ID_NOT,
            CATH_INSTR_ID_OR,
            CATH_INSTR_ID_ORI,
            CATH_INSTR_ID_ORM,
            CATH_INSTR_ID_ROTCL,
            CATH_INSTR_ID_ROTCR,
            CATH_INSTR_ID_ROTL,
            CATH_INSTR_ID_ROTR,
            CATH_INSTR_ID_RTE,
            CATH_INSTR_ID_RTS,
            CATH_INSTR_ID_SETT,
            CATH_INSTR_ID_SHAL,
            CATH_INSTR_ID_SHAR,
            CATH_INSTR_ID_SHLL,
            CATH_INSTR_ID_SHLLN,
            CATH_INSTR_ID_SHLR,
            CATH_INSTR_ID_SHLRN,
            CATH_INSTR_ID_SLEEP,
            CATH_INSTR_ID_STCSR,
            CATH_INSTR_ID_STCGBR,
            CATH_INSTR_ID_STCVBR,
            CATH_INSTR_ID_STCSRPD,
            CATH_INSTR_ID_STCGBRPD,
            CATH_INSTR_ID_STCVBRPD,
            CATH_INSTR_ID_STSMACH,
            CATH_INSTR_ID_STSMACL,
            CATH_INSTR_ID_STSPR,
            CATH_INSTR_ID_STSMACHPD,
            CATH_INSTR_ID_STSMACLPD,
            CATH_INSTR_ID_STSPRPD,
            CATH_INSTR_ID_SUB,
            CATH_INSTR_ID_SUBC,
            CATH_INSTR_ID_SUBV,
            CATH_INSTR_ID_SWAPB,
            CATH_INSTR_ID_SWAPW,
            CATH_INSTR_ID_TAS,
            CATH_INSTR_ID_TRAPA,
            CATH_INSTR_ID_TST,
            CATH_INSTR_ID_TSTI,
            CATH_INSTR_ID_TSTM,
            CATH_INSTR_ID_XOR,
            CATH_INSTR_ID_XORI,
            CATH_INSTR_ID_XORM,
            CATH_INSTR_ID_XTRCT,
            CATH_INSTR_ID_ALL_MAX
        };

        ////////////////////////////////////////
        //         FUNCTION PROTOTYPES
        ////////////////////////////////////////

        std::string GET_OPCODE_NAME(CATH_INSTR_ID_CXX ID) noexcept;
    }
}

#endif