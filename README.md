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

## References:

[SEGA SATURN TECHNICAL SPECIFICTATION](https://segaretro.org/Sega_Saturn/Technical_specifications#cite_note-:File:ST-103-R1-040194.pdf_p-18)

[SUPERH1/2 PROGRAMMING MANUAL](http://bitsavers.informatik.uni-stuttgart.de/components/hitachi/superH/1995_SH1_SH2_Programming_Manual_3rd_Edition.pdf)

[SUPERH2 DSP](https://datasheet.octopart.com/HS6000EIP01H-Renesas-datasheet-11547753.pdf)
