/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mc_hash.h                                                                              */
/* \brief: Provide a hash-like data structure                                                    */
/*                                                                                               */
/* \Expects: mc_type.h is linked properly and defines types needed                               */
/*                                                                                               */
/* ********************************************************************************************* */

#ifndef MC_TEST_STACK_H
#define MC_TEST_STACK_H

/**
 * \brief Test Stack init and clear functionality
 */
void Test_MC_Stack_InitAndFree(void);

/**
 * \brief Test Stack of huge sizes, and working ok
 */
void Test_MC_Stack_BigSize(void);

/**
 * \brief Test Pushing of dynamic and non dynamic values
 */
void Test_MC_Stack_DynamicInsertion(void);

/**
 * \brief Test Stack Peek and Pop functionality
 */
void Test_MC_Stack_PeekAndPop(void);

/**
 * \brief Test Stack is empty after init, pushes and pops til empty for consistency
 */
void Test_MC_Stack_IsEmpty(void);

/**
 * \brief Test Stack getsize functionality after various pushes and pops
 */
void Test_MC_Stack_GetSize(void);

/**
 * \brief Main exposed module for all unit tests of type MC_Stack
 *
 * \details Package all the mar core stack unit tests
 */
void Test_MC_Module_Stack(void);

#endif
