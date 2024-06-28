/* ******************************************* */
/* File stamp: 06/2024                         */
/* Author: Mario Migliacio                     */
/* Project: Mar.io                             */
/* ******************************************* */

#ifndef MAR_CORE_TYPE_H
#define MAR_CORE_TYPE_H

/*
 * @file mar_core_type.h 
 * Provide simple type utlity
 */

/* ***********************************/
/*            (template)             */
/* ***********************************/

#include <stdint.h>

/* ***********************************/
/* Unsigned Typedef definitions      */
/* ***********************************/

/*
 * \brief unsigned 8 bit value. Range: (0, 255)
 */
typedef uint8_t u8;

/*
 * \brief unsigned 16 bit value. Range: (0, 65,535)
 */
typedef uint16_t u16;

/*
 * \brief unsigned 32 bit value. Range: (0, 4,294,967,295)
 */
typedef uint32_t u32;

/*
 * \brief unsigned 64 bit value. Range: (0, 18,446,744,073,709,551,615)
 */
typedef uint64_t u64;

/* ***********************************/
/* Signed Typedef definitions        */
/* ***********************************/

/*
 * \brief signed 8 bit value. Range: (-128, 127)
 */
typedef int8_t i8;

/*
 * \brief signed 16 bit value. Range: (-32,768, 32,767)
 */
typedef int16_t i16;

/*
 * \brief signed 32 bit value. Range: (-2,147,483,648, 2,147,483,647)
 */
typedef int32_t i32;

/*
 * \brief signed 64 bit value. Range: (−9,223,372,036,854,775,808, 9,223,372,036,854,775,807)
 */
typedef int64_t i64;

/* ***********************************/
/* Preprocessor definitions          */
/* ***********************************/

/*
 * \brief represents the maximum 8 bit unsigned value: 255
 */
#define U8_MAX UINT8_MAX

/*
 * \brief represents the maximum 16 bit unsigned value: 65535
 */
#define U16_MAX UINT16_MAX

/*
 * \brief represents the maximum 32 bit unsigned value: 4294967295
 */
#define U32_MAX UINT32_MAX

/*
 * \brief represents the maximum 64 bit unsigned value: 18446744073709551615
 */
#define U64_MAX UINT64_MAX

/*
 * \brief represents the minimum 8 bit signed value: -128
 */
#define I8_MIN INT8_MIN

/*
 * \brief represents the minimum 16 bit signed value: -32768
 */
#define I16_MIN INT16_MIN

/*
 * \brief represents the minimum 32 bit signed value: -2,147,483,648
 */
#define I32_MIN INT32_MIN

/*
 * \brief represents the minimum 64 bit signed value: −9,223,372,036,854,775,808
 */
#define I64_MIN INT64_MIN

/*
 * \brief represents the maximum 8 bit signed value: 255
 */
#define I8_MAX INT8_MAX

/*
 * \brief represents the maximum 16 bit signed value: 32,767
 */
#define I16_MAX INT16_MAX

/*
 * \brief represents the maximum 32 bit signed value: 2,147,483,647
 */
#define I32_MAX INT32_MAX

/*
 * \brief represents the maximum 64 bit signed value: 9,223,372,036,854,775,807
 */
#define I64_MAX INT64_MAX

/* ***********************************/
/* Bit Masking and handling          */
/* ***********************************/

/* 
 * \brief Sets the bit 'val' at position 'pos'
 */
#define SET_BIT(val, pos) ((val) |= (1U << (pos)))

/*
* \brief Clears the bit 'val' at position 'pos'
*/
#define CLEAR_BIT(val, pos) ((val) &= ~(1U << (pos)))

/*
* \brief Changes the bit 'val' at position 'pos' from 0 to 1, or 1 to 0
*/
#define TOGGLE_BIT(val, pos) ((val) ^= (1U << (pos)))

/*
* \brief Returns the truth value of if the bit 'val' at position 'pos' is 1
*/
#define IS_BIT_SET(val, pos) (((val) & (1U << (pos))) != 0)

#endif
