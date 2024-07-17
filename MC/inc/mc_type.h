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

#define MASK_0  (0LL << 0)
#define MASK_1  (1LL << 0)
#define MASK_2  (1LL << 1)
#define MASK_3  (1LL << 2)
#define MASK_4  (1LL << 3)
#define MASK_5  (1LL << 4)
#define MASK_6  (1LL << 5)
#define MASK_7  (1LL << 6)
#define MASK_8  (1LL << 7)
#define MASK_9  (1LL << 8)
#define MASK_10 (1LL << 9)
#define MASK_11 (1LL << 10)
#define MASK_12 (1LL << 11)
#define MASK_13 (1LL << 12)
#define MASK_14 (1LL << 13)
#define MASK_15 (1LL << 14)
#define MASK_16 (1LL << 15)
#define MASK_17 (1LL << 16)
#define MASK_18 (1LL << 17)
#define MASK_19 (1LL << 18)
#define MASK_20 (1LL << 19)
#define MASK_21 (1LL << 20)
#define MASK_22 (1LL << 21)
#define MASK_23 (1LL << 22)
#define MASK_24 (1LL << 23)
#define MASK_25 (1LL << 24)
#define MASK_26 (1LL << 25)
#define MASK_27 (1LL << 26)
#define MASK_28 (1LL << 27)
#define MASK_29 (1LL << 28)
#define MASK_30 (1LL << 29)
#define MASK_31 (1LL << 30)
#define MASK_32 (1LL << 31)
#define MASK_33 (1LL << 32)
#define MASK_34 (1LL << 33)
#define MASK_35 (1LL << 34)
#define MASK_36 (1LL << 35)
#define MASK_37 (1LL << 36)
#define MASK_38 (1LL << 37)
#define MASK_39 (1LL << 38)
#define MASK_40 (1LL << 39)
#define MASK_41 (1LL << 40)
#define MASK_42 (1LL << 41)
#define MASK_43 (1LL << 42)
#define MASK_44 (1LL << 43)
#define MASK_45 (1LL << 44)
#define MASK_46 (1LL << 45)
#define MASK_47 (1LL << 46)
#define MASK_48 (1LL << 47)
#define MASK_49 (1LL << 48)
#define MASK_50 (1LL << 49)
#define MASK_51 (1LL << 50)
#define MASK_52 (1LL << 51)
#define MASK_53 (1LL << 52)
#define MASK_54 (1LL << 53)
#define MASK_55 (1LL << 54)
#define MASK_56 (1LL << 55)
#define MASK_57 (1LL << 56)
#define MASK_58 (1LL << 57)
#define MASK_59 (1LL << 58)
#define MASK_60 (1LL << 59)
#define MASK_61 (1LL << 60)
#define MASK_62 (1LL << 61)
#define MASK_63 (1LL << 62)

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
