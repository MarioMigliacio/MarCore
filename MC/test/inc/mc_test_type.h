/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mc_test.h                                                                              */
/* \brief: Test prototypes for the types interface                                               */
/*                                                                                               */
/* \Expects: No expectations are made prior to type definitions in this file                     */
/*                                                                                               */
/* ********************************************************************************************* */

#ifndef MC_TEST_TYPE_H
#define MC_TEST_TYPE_H

/**
 * \brief Test type Unsigned Max Values Are Correct
 *
 * \details Stress the type definitions and values
 */
u32 Test_MC_Type_UintMaxValsCorrect(void);

/**
 * \brief Test type Unsigned Overflow Expected
 *
 * \details Stress the type definitions and values
 */
u32 Test_MC_Type_UintMaxOverflowCorrect(void);

/**
 * \brief Test type Signed Min Values Are Correct
 *
 * \details Stress the type definitions and values
 */
u32 Test_MC_Type_IntMinValsCorrect(void);

/**
 * \brief Test type Signed Max Values Are Correct
 *
 * \details Stress the type definitions and values
 */
u32 Test_MC_Type_IntMaxValsCorrect(void);

/**
 * \brief Test type Setting bits Are Correct
 *
 * \details Stress the type definitions and values
 */
u32 Test_MC_Type_SetBitCorrect(void);

/**
 * \brief Test type Clearing bits Are Correct
 *
 * \details Stress the type definitions and values
 */
u32 Test_MC_Type_ClearBitCorrect(void);

/**
 * \brief Test type Toggle bits Are Correct
 *
 * \details Stress the type definitions and values
 */
u32 Test_MC_Type_ToggleBitCorrect(void);

/**
 * \brief Test type Bit mask boolean Is Correct
 *
 * \details Stress the type definitions and values
 */
u32 Test_MC_Type_IsBitSetCorrect(void);

#endif
