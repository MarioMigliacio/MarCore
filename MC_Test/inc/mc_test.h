/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mc_test.h                                                                              */
/* \brief: Header collection with function prototypes for testing                                */
/*                                                                                               */
/* \Expects: mac_test definitions are defined and linked properly                                */
/*                                                                                               */
/* ********************************************************************************************* */

// MARIO TODO: abstract test interface per module, link properly
// this header needs the assert, and file headers, and provide the test_module<x> prototype.
// the prototype <x> should have its own header and corresponding c file.

#ifndef MC_TEST_H
#define MC_TEST_H

/**
 * \brief Test type Unsigned Max Values Are Correct
 *
 * \details Stress the type definitions and values
 */
void Test_MC_Type_UintMaxValsCorrect(void);

/**
 * \brief Test type Unsigned Overflow Expected
 *
 * \details Stress the type definitions and values
 */
void Test_MC_Type_UintMaxOverflowCorrect(void);

/**
 * \brief Test type Signed Min Values Are Correct
 *
 * \details Stress the type definitions and values
 */
void Test_MC_Type_IntMinValsCorrect(void);

/**
 * \brief Test type Signed Max Values Are Correct
 *
 * \details Stress the type definitions and values
 */
void Test_MC_Type_IntMaxValsCorrect(void);

/**
 * \brief Main exposed module for all unit tests of type mario_core_type
 *
 * \details Package all the mar core type unit tests
 */
void Test_MC_Module_Type(void);

/**
 * \brief Run All Tests runs every module that has defined unit tests.
 */
void Run_All_Tests(void);

#endif
