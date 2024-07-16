/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mc_type.h                                                                              */
/* \brief: Provide simple type utlity                                                            */
/*                                                                                               */
/* \Expects: No expectations are made prior to type definitions in this file                     */
/*                                                                                               */
/* ********************************************************************************************* */

#ifndef MC_TYPE_H
#define MC_TYPE_H

#include <stdint.h>

/* ***********************************/
/* Preprocessor definitions          */
/* ***********************************/

/**
 * \brief represents the typical false logic, 0. Useful so we don't have to include <stdbool.h>
 */
#define FALSE 0

/**
 * \brief represents the typical true logic, 1. Useful so we don't have to include <stdbool.h>
 */
#define TRUE 1

/**
 * \brief represents the maximum 8 bit unsigned value: 255
 */
#define U8_MAX UINT8_MAX

/**
 * \brief represents the maximum 16 bit unsigned value: 65,535
 */
#define U16_MAX UINT16_MAX

/**
 * \brief represents the maximum 32 bit unsigned value: 4,294,967,295
 */
#define U32_MAX UINT32_MAX

/**
 * \brief represents the maximum 64 bit unsigned value: 18,446,744,073,709,551,615
 */
#define U64_MAX UINT64_MAX

/**
 * \brief represents the minimum 8 bit signed value: -128
 */
#define I8_MIN INT8_MIN

/**
 * \brief represents the minimum 16 bit signed value: -32,768
 */
#define I16_MIN INT16_MIN

/**
 * \brief represents the minimum 32 bit signed value: -2,147,483,648
 */
#define I32_MIN INT32_MIN

/**
 * \brief represents the minimum 64 bit signed value: −9,223,372,036,854,775,808
 */
#define I64_MIN INT64_MIN

/**
 * \brief represents the maximum 8 bit signed value: 255
 */
#define I8_MAX INT8_MAX

/**
 * \brief represents the maximum 16 bit signed value: 32,767
 */
#define I16_MAX INT16_MAX

/**
 * \brief represents the maximum 32 bit signed value: 2,147,483,647
 */
#define I32_MAX INT32_MAX

/**
 * \brief represents the maximum 64 bit signed value: 9,223,372,036,854,775,807
 */
#define I64_MAX INT64_MAX

/* ***********************************/
/* Bit Masking and handling          */
/* ***********************************/

/**
 * \brief Sets the bit 'val' at position 'pos'
 */
#define SET_BIT(val, pos) ((val) |= (1LL << (pos)))

/**
* \brief Clears the bit 'val' at position 'pos'
*/
#define CLEAR_BIT(val, pos) ((val) &= ~(1LL << (pos)))

/**
* \brief Changes the bit 'val' at position 'pos' from 0 to 1, or 1 to 0
*/
#define TOGGLE_BIT(val, pos) ((val) ^= (1LL << (pos)))

/**
* \brief Returns the truth value of if the bit 'val' at position 'pos' is 1
*/
#define IS_BIT_SET(val, pos) (((val) & (1LL << (pos))) != 0)


/**
 * MASK_0 - MASK_64 are useful for efficiently packing
 * many variables or options into one single u64.
 */

#define MASK_0  0x0
#define MASK_1  0x1
#define MASK_2  0x3
#define MASK_3  0x7
#define MASK_4  0xF
#define MASK_5  0x1F
#define MASK_6  0x3F
#define MASK_7  0x7F
#define MASK_8  0xFF
#define MASK_9  0x1FF
#define MASK_10 0x3FF
#define MASK_11 0x7FF
#define MASK_12 0xFFF
#define MASK_13 0x1FFF
#define MASK_14 0x3FFF
#define MASK_15 0x7FFF
#define MASK_16 0xFFFF
#define MASK_17 0x1FFFF
#define MASK_18 0x3FFFF
#define MASK_19 0x7FFFF
#define MASK_20 0xFFFFF
#define MASK_21 0x1FFFFF
#define MASK_22 0x3FFFFF
#define MASK_23 0x7FFFFF
#define MASK_24 0xFFFFFF
#define MASK_25 0x1FFFFFF
#define MASK_26 0x3FFFFFF
#define MASK_27 0x7FFFFFF
#define MASK_28 0xFFFFFFF
#define MASK_29 0x1FFFFFFF
#define MASK_30 0x3FFFFFFF
#define MASK_31 0x7FFFFFFF
#define MASK_32 0xFFFFFFFF
#define MASK_33 0x1FFFFFFFF
#define MASK_34 0x3FFFFFFFF
#define MASK_35 0x7FFFFFFFF
#define MASK_36 0xFFFFFFFFF
#define MASK_37 0x1FFFFFFFFF
#define MASK_38 0x3FFFFFFFFF
#define MASK_39 0x7FFFFFFFFF
#define MASK_40 0xFFFFFFFFFF
#define MASK_41 0x1FFFFFFFFFF
#define MASK_42 0x3FFFFFFFFFF
#define MASK_43 0x7FFFFFFFFFF
#define MASK_44 0xFFFFFFFFFFF
#define MASK_45 0x1FFFFFFFFFFF
#define MASK_46 0x3FFFFFFFFFFF
#define MASK_47 0x7FFFFFFFFFFF
#define MASK_48 0xFFFFFFFFFFFF
#define MASK_49 0x1FFFFFFFFFFFF
#define MASK_50 0x3FFFFFFFFFFFF
#define MASK_51 0x7FFFFFFFFFFFF
#define MASK_52 0xFFFFFFFFFFFFF
#define MASK_53 0x1FFFFFFFFFFFFF
#define MASK_54 0x3FFFFFFFFFFFFF
#define MASK_55 0x7FFFFFFFFFFFFF
#define MASK_56 0xFFFFFFFFFFFFFF
#define MASK_57 0x1FFFFFFFFFFFFFF
#define MASK_58 0x3FFFFFFFFFFFFFF
#define MASK_59 0x7FFFFFFFFFFFFFF
#define MASK_60 0xFFFFFFFFFFFFFFF
#define MASK_61 0x1FFFFFFFFFFFFFFF
#define MASK_62 0x3FFFFFFFFFFFFFFF
#define MASK_63 0x7FFFFFFFFFFFFFFF

/* ***********************************/
/* Unsigned Typedef definitions      */
/* ***********************************/

/**
 * \brief unsigned 8 bit value. Range: (0, 255)
 */
typedef uint8_t u8;

/**
 * \brief unsigned 16 bit value. Range: (0, 65,535)
 */
typedef uint16_t u16;

/**
 * \brief unsigned 32 bit value. Range: (0, 4,294,967,295)
 */
typedef uint32_t u32;

/**
 * \brief unsigned 64 bit value. Range: (0, 18,446,744,073,709,551,615)
 */
typedef uint64_t u64;

/* ***********************************/
/* Signed Typedef definitions        */
/* ***********************************/

/**
 * \brief signed 8 bit value. Range: (-128, 127)
 */
typedef int8_t i8;

/**
 * \brief signed 16 bit value. Range: (-32,768, 32,767)
 */
typedef int16_t i16;

/**
 * \brief signed 32 bit value. Range: (-2,147,483,648, 2,147,483,647)
 */
typedef int32_t i32;

/**
 * \brief signed 64 bit value. Range: (−9,223,372,036,854,775,808, 9,223,372,036,854,775,807)
 */
typedef int64_t i64;

#endif
