// COPYRIGHT (C) HARRY CLARK 2025
// HITACHI SUPERH INSTRUCTION DECODER

// THIS FILE PERTAINS TOWARDS THE MODULARISATION AND LAYOUT OF THE REGISTERS
// IDENTIFIERS, THEIR RESPECTIVE CHARACTERISTICS, THE CONCATENATION OF TYPES
// AND HELPER FUNCTIONS - ALL PERTAINING TOWARDS THE DSP REGISTERS

#ifndef CATH_DSP_REGISTER_H
#define CATH_DSP_REGISTER_H

#if defined(USE_CATH_DSP_REG)
    #define USE_CATH_DSP_REG
#else
    #define USE_CATH_DSP_REG

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

    // NESTED INCLUDES

    #include "enums/registerDSP.h"
    #include "instructions/instructionDSP.h"
    #include "util.h"

    // DEFINE THE BASIS FOR THE LABELS ENCOMPASSING ALL REGISTER TYPES
    extern const char* CATH_DSP_MC_NAMES[DSP_REG_MC_MAX][2];
    extern const char* CATH_DSP_RA_NAMES[DSP_REG_RA_MAX][2];
    extern const char* CATH_DSP_CT_NAMES[DSP_REG_CT_MAX][2];
    extern const char* CATH_DSP_SPECIAL_NAMES[DSP_REG_SPECIAL_MAX];

    // DEFINE THE BASIS FOR THE D1 BUS DESTINATION AND SOURCE SELECTION TABLES
    // INDEXED BY BITS 11-8 ANDS BITS 3-0 OF THE D1 BUS FIELD RESPECTIVELY 
    extern const char* CATH_DSP_D_DEST_NAMES[16];
    extern const char* CATH_DSP_D_SRC_NAMES[16];

    //////////////////////////////////////////
    //         FUNCTION PROTOTYPES
    //////////////////////////////////////////

    extern const char* CATH_REGISTER_GET_MC_NAME(U8);
    extern const char* CATH_REGISTER_GET_CT_NAME(U8);
    extern const char* CATH_REGISTER_GET_RAM_ADDR_NAME(U8);

#ifdef __cplusplus
}

#endif
#endif
#endif
