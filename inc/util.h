// COPYRIGHT (C) HARRY CLARK 2025
// HITACHI SUPERH INSTRUCTION DECODER

// THE FOLLOWING FILE PERTAINS TOWARDS THE FUNCTIONALITY ENCOMPASSING
// UTILIES FOR VARIOUS BIT OPERATIONS AND ANYTHING OF THE ASSOCIATION

#ifndef CATH_UTIL_H
#define CATH_UTIL_H

// NESTED INCLUDES

#include <common.h>

// SYSTEM INCLUDES

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

    // CREATE THE BASIS FOR GENERAL PURPOSE BIT SHIFT OPERATIONS
    // 
    // FOR SHIFT_L - LOWER BITS ARE MASKED, THEN SHIFTED
    // FOR SHIFT_R - VALUE IS SHIFTED, THEN LOWER BITS ARE MASKED

    #define         CATH_MASK(VALUE, WORD)                      ((VALUE) & ((1U << (WORD)) - 1U))
    #define         CATH_SHIFT_L(VALUE, SHIFT, WORD)            (CATH_MASK((VALUE), (WORD)) <<  (SHIFT))
    #define         CATH_SHIFT_R(VALUE, SHIFT, WORD)            (CATH_MASK((VALUE) >> (SHIFT), (WORD)))


#ifdef __cplusplus
}
#endif
#endif
