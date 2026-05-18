// COPYRIGHT (C) HARRY CLARK 2025
// HITACHI SUPERH INSTRUCTION DECODER

// THIS FILE PERTAINS TOWARDS THE MODULARISATION AND LAYOUT OF THE REGISTERS
// IDENTIFIERS, THEIR RESPECTIVE CHARACTERISTICS, THE CONCATENATION OF TYPES
// AND HELPER FUNCTIONS - ALL PERTAINING TOWARDS THE REGISTERS

// NESTED INCLUDES  

#include "instructions/registerDSP.h"

#define USE_CATH_DSP_REG

// RESOLVE A 3-BIT MC FIELD DEPENDING ON BUS ACCESS
// TO DETERMINE THE REGISTER NAME
//
// USED BY X/Y/D BUS SOURCE OPERANDS
const char* CATH_DSP_MC_NAMES[DSP_REG_MC_MAX][2] =
{
    [DSP_REG_MC0]   =   { "MC0", "mc0" },
    [DSP_REG_MC1]   =   { "MC1", "mc1" },
    [DSP_REG_MC2]   =   { "MC2", "mc2" },
    [DSP_REG_MC3]   =   { "MC3", "mc3" },
};

const char* CATH_DSP_CT_NAMES[DSP_REG_CT_MAX][2] =
{
    [DSP_REG_CT0]   =   { "CT0", "ct0" },
    [DSP_REG_CT1]   =   { "CT1", "ct1" },
    [DSP_REG_CT2]   =   { "CT2", "ct2" },
    [DSP_REG_CT3]   =   { "CT3", "ct3" },
};

const char* CATH_DSP_RA_NAMES[DSP_REG_RA_MAX][2] =
{
    [DSP_REG_RA0]   =   { "RAM0", "ram0" },
    [DSP_REG_RA1]   =   { "RAM1", "ram1" },
    [DSP_REG_RA2]   =   { "RAM2", "ram2" },
    [DSP_REG_RA3]   =   { "RAM3", "ram3" },
};

// SPECIFIC FIELDS ARE OUTLINED AS NULL AS A 
// RESULT OF THEM BEING UNUSED PATTERNS

const char* CATH_DSP_D_DEST_NAMES[16] = 
{
    [0x0]   =   "MC0",
    [0x1]   =   "MC1",
    [0x2]   =   "MC2",
    [0x3]   =   "MC3",
    [0x4]   =   "RX",
    [0x5]   =   "PL",
    [0x6]   =   "RA0",
    [0x7]   =   "WA0",
    [0x8]   =   NULL,
    [0x9]   =   NULL,
    [0xA]   =   "LOP",
    [0xB]   =   "TOP",
    [0xC]   =   "M0",
    [0xD]   =   "M1",
    [0xE]   =   "M2",
    [0xF]   =   "M3",
};

const char* CATH_DSP_X_SRC_NAMES[8] =
{
    [0x0]   =   "M0",   
    [0x1]   =   "M1",
    [0x2]   =   "M2",   
    [0x3]   =   "M3",
    [0x4]   =   "MC0",  
    [0x5]   =   "MC1",
    [0x6]   =   "MC2",  
    [0x7]   =   "MC3",
};

const char* CATH_DSP_Y_SRC_NAMES[8] =
{
    [0x0]   =   "M0",   
    [0x1]   =   "M1",
    [0x2]   =   "M2",   
    [0x3]   =   "M3",
    [0x4]   =   "MC0",  
    [0x5]   =   "MC1",
    [0x6]   =   "MC2",  
    [0x7]   =   "MC3",
};

const char* CATH_DSP_D_SRC_NAMES[16] =
{
    [0x0]   =   "M0",   
    [0x1]   =   "M1",
    [0x2]   =   "M2",   
    [0x3]   =   "M3",
    [0x4]   =   "MC0",  
    [0x5]   =   "MC1",
    [0x6]   =   "MC2",  
    [0x7]   =   "MC3",
    [0x8]   =   NULL,
    [0x9]   =   "ALU LOW",
    [0xA]   =   "ALU HIGH",
    [0xB]   =   NULL,   
    [0xC]   =   NULL,
    [0xD]   =   NULL,   
    [0xE]   =   NULL,
    [0xF]   =   NULL,
};

const char* CATH_DSP_SPECIAL_NAMES[DSP_REG_SPECIAL_MAX] = 
{
    [DSP_REG_ACC]   =   "ACC",
    [DSP_REG_ALU]   =   "ALU",
    [DSP_REG_MUL]   =   "MUL",
    [DSP_REG_PC]    =   "PC",
    [DSP_REG_TOP]   =   "TOP",
    [DSP_REG_LOP]   =   "LOP",
    [DSP_REG_ALL]   =   "ALL",
};

const char* CATH_DSP_MVI_DEST_NAMES[32] = 
{
    [0x00] = "MC0",  [0x01] = "MC1",
    [0x02] = "MC2",  [0x03] = "MC3",
    [0x04] = "RX",   [0x05] = NULL,
    [0x06] = NULL,   [0x07] = NULL,
    [0x08] = NULL,   [0x09] = NULL,
    [0x0A] = "LOP",  [0x0B] = "TOP",
    [0x0C] = "CT0",  [0x0D] = "CT1",
    [0x0E] = "CT2",  [0x0F] = "CT3",
};
