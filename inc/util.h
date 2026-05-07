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
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

    // CREATE THE BASIS FOR GENERAL PURPOSE BIT SHIFT OPERATIONS
    // 
    // FOR SHIFT_L - LOWER BITS ARE MASKED, THEN SHIFTED
    // FOR SHIFT_R - VALUE IS SHIFTED, THEN LOWER BITS ARE MASKED
    // BITFULL - MASKS AND SHIFTS THE FULL MANTISSA OF BITS WITHIN A SEQUENCE

    #define         CATH_ARRAY(ARRAY)                           (sizeof(ARRAY) / sizeof((ARRAY)[0]))
    #define         CATH_MASK(VALUE, WORD)                      ((VALUE) & ((1U << (WORD)) - 1U))
    #define         CATH_SHIFT_L(VALUE, SHIFT, WORD)            (CATH_MASK((VALUE), (WORD)) <<  (SHIFT))
    #define         CATH_SHIFT_R(VALUE, SHIFT, WORD)            (CATH_MASK((VALUE) >> (SHIFT), (WORD)))
    #define         CATH_BITFULL(FULL, VALUE, SHIFT, WORD)      ((CATH_SHIFT_R((FULL), (SHIFT) + (WORD), 32U - ((SHIFT) + (WORD))) | CATH_SHIFT_L((VALUE, (SHIFT), (WORD)) | CATH_MASK((FULL), (SHIFT)))))

    // PACKS BITS BASED ON THEIR WIDTH
    // HELPS WITH ACCOMMODATING FOR EXTRACTING BITS
    // FROM MULTI-OPERAND INSTRUCTIONS SUCH AS DSP INSTRUCTIONS
    #define         CATH_PACK_BITS(WORD, VALUE, SHIFT, WIDTH)       \
            (((WORD) & ~(((1U << (WIDTH)) -1) << (SHIFT))) |        \
            (((VALUE) & ((1U << (WIDTH)) - 1)) << (SHIFT)))


    // DEFINE THE CHARACTERISTICS PER REGISTER TYPE
    // TO BE ABLE TO READ PROPERLY FROM THEIR RESPECTIVE ENUM
    typedef enum CATH_REG_ALIAS
    {
        CATH_REG_UPPER,
        CATH_REG_LOWER,
        
    } CATH_REG_ALIAS;

    // SIMPLE CONFIG TO HOUSE THE CHARACTERISTICS
    // ENCOMPASSING REGISTER TYPES
    typedef struct CATH_CONFIG
    {
        CATH_REG_ALIAS REG_ALIAS;
        bool USE_ALIAS;

    } CATH_CONFIG;

    extern CATH_CONFIG CC;
    
#ifdef __cplusplus
}
#endif
#endif
