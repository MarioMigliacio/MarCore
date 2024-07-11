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
#define SET_BIT(val, pos) ((val) |= (1U << (pos)))

/**
* \brief Clears the bit 'val' at position 'pos'
*/
#define CLEAR_BIT(val, pos) ((val) &= ~(1U << (pos)))

/**
* \brief Changes the bit 'val' at position 'pos' from 0 to 1, or 1 to 0
*/
#define TOGGLE_BIT(val, pos) ((val) ^= (1U << (pos)))

/**
* \brief Returns the truth value of if the bit 'val' at position 'pos' is 1
*/
#define IS_BIT_SET(val, pos) (((val) & (1U << (pos))) != 0)


/**
 * MASK_0 - MASK_64 are useful for efficiently packing
 * many variables or options into one single u64.
 */

#define MASK_0                  0x1
#define MASK_1                  0x2
#define MASK_2                  0x4
#define MASK_3                  0x8
#define MASK_4                 0x10
#define MASK_5                 0x20
#define MASK_6                 0x40
#define MASK_7                 0x80
#define MASK_8                0x100
#define MASK_9                0x200
#define MASK_10               0x400
#define MASK_11               0x800
#define MASK_12              0x1000
#define MASK_13              0x2000
#define MASK_14              0x4000
#define MASK_15              0x8000
#define MASK_16             0x10000
#define MASK_17             0x20000
#define MASK_18             0x40000
#define MASK_19             0x80000
#define MASK_20            0x100000
#define MASK_21            0x200000
#define MASK_22            0x400000
#define MASK_23            0x800000
#define MASK_24           0x1000000
#define MASK_25           0x2000000
#define MASK_26           0x4000000
#define MASK_27           0x8000000
#define MASK_28          0x10000000
#define MASK_29          0x20000000
#define MASK_30          0x40000000
#define MASK_31          0x80000000
#define MASK_32         0x100000000
#define MASK_33         0x200000000
#define MASK_34         0x400000000
#define MASK_35         0x800000000
#define MASK_36        0x1000000000
#define MASK_37        0x2000000000
#define MASK_38        0x4000000000
#define MASK_39        0x8000000000
#define MASK_40       0x10000000000
#define MASK_41       0x20000000000
#define MASK_42       0x40000000000
#define MASK_43       0x80000000000
#define MASK_44      0x100000000000
#define MASK_45      0x200000000000
#define MASK_46      0x400000000000
#define MASK_47      0x800000000000
#define MASK_48     0x1000000000000
#define MASK_49     0x2000000000000
#define MASK_50     0x4000000000000
#define MASK_51     0x8000000000000
#define MASK_52    0x10000000000000
#define MASK_53    0x20000000000000
#define MASK_54    0x40000000000000
#define MASK_55    0x80000000000000
#define MASK_56   0x100000000000000
#define MASK_57   0x200000000000000
#define MASK_58   0x400000000000000
#define MASK_59   0x800000000000000
#define MASK_60  0x1000000000000000
#define MASK_61  0x2000000000000000
#define MASK_62  0x4000000000000000
#define MASK_63  0x8000000000000000

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
