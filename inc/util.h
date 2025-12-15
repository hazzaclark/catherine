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

    #define         CATH_MASK(VALUE, WORD)                      ((VALUE) & ((1U << (WORD)) - 1U))
    #define         CATH_SHIFT_L(VALUE, SHIFT, WORD)            (CATH_MASK((VALUE), (WORD)) <<  (SHIFT))
    #define         CATH_SHIFT_R(VALUE, SHIFT, WORD)            (CATH_MASK((VALUE) >> (SHIFT), (WORD)))
    #define         CATH_BITFULL(FULL, VALUE, SHIFT, WORD)      ((CATH_SHIFT_R((FULL), (SHIFT) + (WORD), 32U - ((SHIFT) + (WORD))) | CATH_SHIFT_L((VALUE, (SHIFT), (WORD)) | CATH_MASK((FULL), (SHIFT)))))

    // CREATES A DIRECTIVE TO HELP WITH PRE-PROCESSED 
    // BUFFER SIZES AT COMPILE TIME
    // 
    // DETERMINES THE CURRENT SIZE AND ADDS TO
    // THE TOTAL - HELPS WITH POSITIONS OF BUFFER READERS

    #define         CATH_BUFFER(BUFFER, SIZE, EXP)              \
        do                                                      \
        {                                                       \
            UNK TEMP_SIZE = (UNK)(EXP);                         \
            if((BUFFER) != NULL)                                \
            {                                                   \
                (BUFFER) += TEMP_SIZE;                          \
            }                                                   \
            (SIZE) += TEMP_SIZE;                                \
                                                                \
        } while(0)


    // DEFINE THE BASIS FOR BEING ABLE TO LEVERAGE 
    // SPRINTF FOR AIDING IN STRING FORMATTING  

    #define         CATH_SPRINTF(BUFFER, SIZE, FMT, ...)        \
        do                                                      \  
        {                                                       \
            int LENGTH;                                         \
            if((BUFFER) != NULL)                                \
            {                                                   \
                LENGTH = sprintf(BUFFER, FMT, __VA_ARGS__);     \
            }                                                   \
            else                                                \
            {                                                   \
                LENGTH = snprintf(NULL, 0, FMT, __VA_ARGS__);   \
            }                                                   \
                                                                \
            CATH_BUFFER(BUFFER, SIZE, LENGTH);                  \
                                                                \
        } while(0)

    // COPY THE CURRENT STRING HOUSED WITHIN THE BUFFER 
    // INTO THE MAIN BUFFER STREAM
    #define         CATH_BUFFER_CPY(BUFFER, SIZE, FMT)          \
        do                                                      \
        {                                                       \
            UNK TEMP_SIZE = strlen(FMT);                        \
            if((BUFFER) != NULL)                                \   
            {                                                   \
                memcpy(BUFFER, FMT, TEMP_SIZE);              \
            }                                                   \
                                                                \
            CATH_BUFFER(BUFFER, SIZE, TEMP_SIZE);               \
        } while(0)  

#ifdef __cplusplus
}
#endif
#endif
