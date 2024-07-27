/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mc_guid.h                                                                              */
/* \brief: Test prototypes for the guid interface                                                */
/*                                                                                               */
/* \Expects: No expectations are made prior to type definitions in this file                     */
/*                                                                                               */
/* ********************************************************************************************* */

#ifndef MC_TEST_GUID_H
#define MC_TEST_GUID_H

#include "mc_type.h"

/**
 * \brief Test Guid generate functionality
 */
u32 Test_MC_Guid_Generate(void);

/**
 * \brief Test Guid string formatting functionality
 */
u32 Test_MC_Guid_Format(void);

#endif
