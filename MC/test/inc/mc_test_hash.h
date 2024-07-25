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
u32 Test_MC_Hash_InitAndFree(void);

/**
 * \brief Test HashMaps of huge sizes, and working ok
 */
u32 Test_MC_Hash_BigSize(void);

/**
 * \brief Test Inserting of dynamic and non dynamic values
 */
u32 Test_MC_Hash_DynamicInsertion(void);

/**
 * \brief Test HashMap searching, and entry removals
 */
u32 Test_MC_Hash_SearchAndRemove(void);

#endif
