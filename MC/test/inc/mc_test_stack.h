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
u32 Test_MC_Stack_InitAndFree(void);

/**
 * \brief Test Stack of huge sizes, and working ok
 */
u32 Test_MC_Stack_BigSize(void);

/**
 * \brief Test Pushing of dynamic and non dynamic values
 */
u32 Test_MC_Stack_DynamicInsertion(void);

/**
 * \brief Test Stack Peek and Pop functionality
 */
u32 Test_MC_Stack_PeekAndPop(void);

/**
 * \brief Test Stack is empty after init, pushes and pops til empty for consistency
 */
u32 Test_MC_Stack_IsEmpty(void);

/**
 * \brief Test Stack getsize functionality after various pushes and pops
 */
u32 Test_MC_Stack_GetSize(void);

#endif
