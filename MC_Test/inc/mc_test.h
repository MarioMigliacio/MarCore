/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mc_test.h                                                                              */
/* \brief: Header collection with function prototypes for testing                                */
/*                                                                                               */
/* \Expects: mc_test definitions are defined and linked properly                                 */
/*                                                                                               */
/* ********************************************************************************************* */

#ifndef MC_TEST_H
#define MC_TEST_H

#include "mc_type.h"
#include "mc_test_assert.h"

/* Include each Moduel after this point */
#include "mc_test_hash.h"
#include "mc_test_type.h"

/**
 * \brief Run All Tests runs every module that has defined unit tests.
 */
void Run_All_Tests(void);

#endif
