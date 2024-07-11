/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mc_hash.h                                                                              */
/* \brief: Provide a hash-like data structure                                                    */
/*                                                                                               */
/* \Expects: mc_type.h is linked properly and defines types needed                               */
/*                                                                                               */
/* ********************************************************************************************* */

#ifndef MC_TEST_HASH_H
#define MC_TEST_HASH_H

/**
 * \brief Test HashMap init and clear functionality
 */
void Test_MC_Hash_InitAndClear(void);

/**
 * \brief Test HashMaps of huge sizes, and working ok
 */
void Test_MC_Hash_BigSize(void);

/**
 * \brief Test Inserting of dynamic and non dynamic values
 */
void Test_MC_Hash_DynamicInsertion(void);

/**
 * \brief Test HashMap searching, and entry removals
 */
void Test_MC_Hash_SearchAndRemove(void);

/**
 * \brief Main exposed module for all unit tests of type MC_Hash
 *
 * \details Package all the mar core type unit tests
 */
void Test_MC_Module_Hash(void);

#endif
