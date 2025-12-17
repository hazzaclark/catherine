# catherine
Hitachi SuperH Instruction Decoder

## Motive:

The ambition behind this project is to provide an all-encompassing API for decoding Hitachi SuperH-related ISA's. Focussing primiarily on the SuperH2 for usage with the SEGA Saturn and it's respective peripherals (though, the API should extend to other ISA's).

The main intention is to provide a simple and static implementation of related ISA's to help with recompilation of architectures.

Inspired by contemporaires such as [rabbitizer](https://github.com/Decompollaborate/rabbitizer), this API aims to implement similar features, with due regard for architectural differences.

## Features:

Given that this API is developed with the SEGA Saturn's architectural design, architectural nuances will be taken into account first-and-foremost. Meaning that the main goal is the account for the dual-CPU configuration and to produce close to matching Assembly:

  - Simple per-word instruction decoding
  - Static Analysis for handling said decoding
  - (WIP) Bindings for C++
  - Multiple SH architectures aim to be suppoerted: with the main focus on SuperH2.
  - SEGA Saturn DSP (SCU)

## Implementation:

Throughout development, the main goal was to make this as dynamic as it is simple to navigate and implement - akin to the likeness and contemporaires of the source inspiration. The main features of this decoder is mapping all of the characteristics of a related instruction in a general sense, to a holistc instruction structure

```c
typedef struct SH_INSTRUCTION
{
    CATH_INSTR_ID INSTR_ID;
    CATH_INSTR_ID_TYPE ID_TYPE;
    const SH_DESCRIPTOR* DESCRIPTOR;
    CATH_INSTR_CAT CATEGORY;
        
    U32 FLAGS;
    U32 PC;
    U16 WORD;
    U32 BITS;

} SH_INSTRUCTION;
```

The most important consideration to make was the inclusion of the descriptor table - mapping these values dynamically in relation to it's operand type, and general characteristics mapped directly from the programmer manual

Each descriptor element corresponds to a wider array which handles all of the above dynamically
```c
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
// ... etc
``` 

From there, the following array is accessed accordingly within the provided decode instruction which processes each unique entry against their respective mask value, bit match and enum value
```c
void CATH_INSTRUCTION_PROCESS(SH_INSTRUCTION* INSTR)
{
  // ...
  if(INSTR->INSTR_ID < CATH_INSTR_ID_ALL_MAX)
  {
    INSTR->DESCRIPTOR = &INSTR_DESCRIPTORS[INSTR->INSTR_ID];
  } 
}
```

## What is the end goal?

The eventual end goal with this instruction decoder is to provide a dynamic and fast implementation for producing matching Assembly based on sophisticated O(1) lookup and extraction from all of the API featrues.

Demonstrated by this snippet of Assembly code from NiGHTS into Dreams [MK-81020] running on the [Ymir](https://github.com/StrikerX3/Ymir/tree/main/) SEGA Saturn Emulator

Note that the following contexts of the Emulator in question serves to provide a differing means of accessing current PC and SR values. Therefore, results of current values passed in through Operand Types such as PC Displacement will differ from source to decoder as we are not too concerned with accessing verbatim SP values (of course barring the fact that the emulator is *emulating* a system and all I am doing is decoding to get matching ASM)

<img width="2062" height="780" alt="image" src="https://github.com/user-attachments/assets/179945fd-43b1-4a41-93b1-ac6c6a18c7ac" />




## References:

[SEGA SATURN TECHNICAL SPECIFICTATION](https://segaretro.org/Sega_Saturn/Technical_specifications#cite_note-:File:ST-103-R1-040194.pdf_p-18)

[SUPERH1/2 PROGRAMMING MANUAL](http://bitsavers.informatik.uni-stuttgart.de/components/hitachi/superH/1995_SH1_SH2_Programming_Manual_3rd_Edition.pdf)

[SUPERH2 DSP](https://datasheet.octopart.com/HS6000EIP01H-Renesas-datasheet-11547753.pdf)
