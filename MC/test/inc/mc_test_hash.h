/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mc_hash.h                                                                              */
/* \brief: Test prototypes for the hash interface                                                */
/*                                                                                               */
/* \Expects: No expectations are made prior to type definitions in this file                     */
/*                                                                                               */
/* ********************************************************************************************* */

#ifndef MC_TEST_HASH_H
#define MC_TEST_HASH_H

#include "mc_type.h"

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
