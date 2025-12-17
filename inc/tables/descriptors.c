    // COPYRIGHT (C) HARRY CLARK 2025
    // HITACHI SUPERH INSTRUCTION DECODER

    // THIS FILE PERTAINS TOWARDS THE DESCRIPTORS FOR EACH INSTRUCTION TYPE

    #include "instructions/instruction.h"

    // INSTRUTION DEFINERS AND CHARACTERISTICS:
    // SEE: https://antime.kapsi.fi/sega/files/h12p0.pdf

    const SH_DESCRIPTOR INSTR_DESCRIPTORS[CATH_INSTR_ID_ALL_MAX] = 
    {
        [CATH_INSTR_ID_INVALID] = {
            .OPERAND_TYPE = {OPERAND_NONE}, 
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false
        },

        [CATH_INSTR_ID_ADD] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_ADDI] = {
            .OPERAND_TYPE = {OPERAND_IMM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_ADDC] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_ADDV] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_AND] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_ANDI] = {
            .OPERAND_TYPE = {OPERAND_IMM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = true,
        },

        [CATH_INSTR_ID_ANDM] = {
            .OPERAND_TYPE = {OPERAND_IMM, OPERAND_AT_R0_GBR, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = true,
        },

        [CATH_INSTR_ID_BF] = {
            .OPERAND_TYPE = {OPERAND_DISP_PC, OPERAND_NONE},
            .IS_BRANCH = true, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_BFS] = {
            .OPERAND_TYPE = {OPERAND_DISP_PC, OPERAND_NONE},
            .IS_BRANCH = true, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = true,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_BRA] = {
            .OPERAND_TYPE = {OPERAND_DISP_PC, OPERAND_NONE},
            .IS_BRANCH = true, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = true,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_BRAF] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_NONE},
            .IS_BRANCH = true, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = true,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_BSR] = {
            .OPERAND_TYPE = {OPERAND_DISP_PC, OPERAND_NONE},
            .IS_BRANCH = true, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = true,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_BSRF] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_NONE},
            .IS_BRANCH = true, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = true,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_BT] = {
            .OPERAND_TYPE = {OPERAND_DISP_PC, OPERAND_NONE},
            .IS_BRANCH = true, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_BTS] = {
            .OPERAND_TYPE = {OPERAND_DISP_PC, OPERAND_NONE},
            .IS_BRANCH = true, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = true,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_CLRMAC] = {
            .OPERAND_TYPE = {OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_CLRT] = {
            .OPERAND_TYPE = {OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_CMPEQ] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_CMPGE] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_CMPGT] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_CMPHI] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = true,
        },

        [CATH_INSTR_ID_CMPHS] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = true,
        },

        [CATH_INSTR_ID_CMPPL] = {
            .OPERAND_TYPE = {OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_CMPPZ] = {
            .OPERAND_TYPE = {OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_CMPSTR] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_CMPEQI] = {
            .OPERAND_TYPE = {OPERAND_IMM, OPERAND_RM, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_DIV0S] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_DIV0U] = {
            .OPERAND_TYPE = {OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = true,
        },

        [CATH_INSTR_ID_DIV1] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_DMULS] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_DMULU] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = true,
        },

        [CATH_INSTR_ID_DT] = {
            .OPERAND_TYPE = {OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_EXTSB] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_EXTSW] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_EXTUB] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = true,
        },

        [CATH_INSTR_ID_EXTUW] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = true,
        },

        [CATH_INSTR_ID_JMP] = {
            .OPERAND_TYPE = {OPERAND_AT_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = true, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = true,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_JSR] = {
            .OPERAND_TYPE = {OPERAND_AT_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = true, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = true,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_LDCSR] = {
            .OPERAND_TYPE = {OPERAND_RN, OPERAND_SR, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_LDCGBR] = {
            .OPERAND_TYPE = {OPERAND_RN, OPERAND_GBR, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_LDCVBR] = {
            .OPERAND_TYPE = {OPERAND_RN, OPERAND_VBR, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_LDCPISR] = {
            .OPERAND_TYPE = {OPERAND_AT_RM_POST_INC, OPERAND_SR, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_LDCPIGBR] = {
            .OPERAND_TYPE = {OPERAND_AT_RM_POST_INC, OPERAND_GBR, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_LDCPIVBR] = {
            .OPERAND_TYPE = {OPERAND_AT_RM_POST_INC, OPERAND_VBR, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_LDSMACH] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_MACH, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_LDSMACL] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_MACL, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_LDSPR] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_PR, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MACW] = {
            .OPERAND_TYPE = {OPERAND_AT_RM_POST_INC, OPERAND_AT_RN_POST_INC, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MACL] = {
            .OPERAND_TYPE = {OPERAND_AT_RM_POST_INC, OPERAND_AT_RN_POST_INC, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOV] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVA] = {
            .OPERAND_TYPE = {OPERAND_AT_DISP_PC_ALIGN, OPERAND_R0, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVT] = {
            .OPERAND_TYPE = {OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVI] = {
            .OPERAND_TYPE = {OPERAND_IMM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVBL] = {
            .OPERAND_TYPE = {OPERAND_AT_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVWL] = {
            .OPERAND_TYPE = {OPERAND_AT_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVLL] = {
            .OPERAND_TYPE = {OPERAND_AT_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVBP] = {
            .OPERAND_TYPE = {OPERAND_AT_RM_POST_INC, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVWP] = {
            .OPERAND_TYPE = {OPERAND_AT_RM_POST_INC, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVLP] = {
            .OPERAND_TYPE = {OPERAND_AT_RM_POST_INC, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVBL0] = {
            .OPERAND_TYPE = {OPERAND_AT_R0_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVWL0] = {
            .OPERAND_TYPE = {OPERAND_AT_R0_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVLL0] = {
            .OPERAND_TYPE = {OPERAND_AT_R0_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVBLG] = {
            .OPERAND_TYPE = {OPERAND_AT_DISP_GBR, OPERAND_R0, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVWLG] = {
            .OPERAND_TYPE = {OPERAND_AT_DISP_GBR, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVLLG] = {
            .OPERAND_TYPE = {OPERAND_AT_DISP_GBR, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVBL4] = {
            .OPERAND_TYPE = {OPERAND_AT_DISP_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVWL4] = {
            .OPERAND_TYPE = {OPERAND_AT_DISP_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVLL4] = {
            .OPERAND_TYPE = {OPERAND_AT_DISP_RN, OPERAND_RM, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVBLP] = {
            .OPERAND_TYPE = {OPERAND_AT_DISP_PC, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVWLP] = {
            .OPERAND_TYPE = {OPERAND_AT_DISP_PC, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVLLP] = {
            .OPERAND_TYPE = {OPERAND_AT_DISP_PC, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVBS] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_AT_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVWS] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_AT_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVLS] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_AT_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVBM] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_AT_RN_PRE_DEC, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVWM] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_AT_RN_PRE_DEC, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVLM] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_AT_RN_PRE_DEC, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVBS0] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_AT_R0_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVWS0] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_AT_R0_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVLS0] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_AT_R0_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVBSG] = {
            .OPERAND_TYPE = {OPERAND_RN, OPERAND_AT_DISP_GBR, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVWSG] = {
            .OPERAND_TYPE = {OPERAND_RN, OPERAND_AT_DISP_GBR, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVLSG] = {
            .OPERAND_TYPE = {OPERAND_RN, OPERAND_AT_DISP_GBR, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVBS4] = {
            .OPERAND_TYPE = {OPERAND_RN, OPERAND_AT_DISP_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVWS4] = {
            .OPERAND_TYPE = {OPERAND_RN, OPERAND_AT_DISP_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MOVLS4] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_AT_DISP_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MUL] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_MULU] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = true,
        },

        [CATH_INSTR_ID_MULS] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_NEG] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_NEGC] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_NOP] = {
            .OPERAND_TYPE = {OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_NOT] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_OR] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_ORI] = {
            .OPERAND_TYPE = {OPERAND_IMM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = true,
        },

        [CATH_INSTR_ID_ORM] = {
            .OPERAND_TYPE = {OPERAND_IMM, OPERAND_AT_R0_GBR, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = true,
        },

        [CATH_INSTR_ID_ROTCL] = {
            .OPERAND_TYPE = {OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_ROTCR] = {
            .OPERAND_TYPE = {OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_ROTL] = {
            .OPERAND_TYPE = {OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_ROTR] = {
            .OPERAND_TYPE = {OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_RTE] = {
            .OPERAND_TYPE = {OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = true, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = true,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_RTS] = {
            .OPERAND_TYPE = {OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = true, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = true,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_SETT] = {
            .OPERAND_TYPE = {OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_SHAL] = {
            .OPERAND_TYPE = {OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_SHAR] = {
            .OPERAND_TYPE = {OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_SHLL] = {
            .OPERAND_TYPE = {OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_SHLLN] = {
            .OPERAND_TYPE = {OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_SHLR] = {
            .OPERAND_TYPE = {OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_SHLRN] = {
            .OPERAND_TYPE = {OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_SLEEP] = {
            .OPERAND_TYPE = {OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = true, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_STCSR] = {
            .OPERAND_TYPE = {OPERAND_SR, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_STCGBR] = {
            .OPERAND_TYPE = {OPERAND_GBR, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_STCVBR] = {
            .OPERAND_TYPE = {OPERAND_VBR, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_STCSRPD] = {
            .OPERAND_TYPE = {OPERAND_SR, OPERAND_AT_RN_PRE_DEC, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_STCGBRPD] = {
            .OPERAND_TYPE = {OPERAND_GBR, OPERAND_AT_RN_PRE_DEC, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_STCVBRPD] = {
            .OPERAND_TYPE = {OPERAND_VBR, OPERAND_AT_RN_PRE_DEC, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_STSMACH] = {
            .OPERAND_TYPE = {OPERAND_MACH, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_STSMACL] = {
            .OPERAND_TYPE = {OPERAND_MACL, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_STSPR] = {
            .OPERAND_TYPE = {OPERAND_PR, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_STSMACHPD] = {
            .OPERAND_TYPE = {OPERAND_MACH, OPERAND_AT_RN_PRE_DEC, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_STSMACLPD] = {
            .OPERAND_TYPE = {OPERAND_MACL, OPERAND_AT_RN_PRE_DEC, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_STSPRPD] = {
            .OPERAND_TYPE = {OPERAND_PR, OPERAND_AT_RN_PRE_DEC, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },
        
        [CATH_INSTR_ID_SUB] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_SUBC] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_SUBV] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_SWAPB] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_SWAPW] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_TAS] = {
            .OPERAND_TYPE = {OPERAND_AT_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_TRAPA] = {
            .OPERAND_TYPE = {OPERAND_IMM, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = true, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_TST] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_TSTI] = {
            .OPERAND_TYPE = {OPERAND_IMM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = true,
        },

        [CATH_INSTR_ID_TSTM] = {
            .OPERAND_TYPE = {OPERAND_IMM, OPERAND_AT_R0_GBR, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = true,
        },

        [CATH_INSTR_ID_XOR] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },

        [CATH_INSTR_ID_XORI] = {
            .OPERAND_TYPE = {OPERAND_IMM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = true,
        },

        [CATH_INSTR_ID_XORM] = {
            .OPERAND_TYPE = {OPERAND_IMM, OPERAND_AT_R0_GBR, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = true,
        },

        [CATH_INSTR_ID_XTRCT] = {
            .OPERAND_TYPE = {OPERAND_RM, OPERAND_RN, OPERAND_NONE},
            .IS_BRANCH = false, .IS_JUMP = false, .IS_JUMP_ADDRESS = false,
            .IS_TRAP = false, .IS_HALT = false, .HAS_DELAY_SLOT = false,
            .IS_FLOAT = false, .IS_UNSIGNED = false,
        },
    };
