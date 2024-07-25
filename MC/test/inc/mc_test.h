/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mc_test.h                                                                              */
/* \brief: Header collection with function prototypes for testing                                */
/*                                                                                               */
/* \Expects: mc_test definitions are defined and linked properly                                 */
/*           Also useful as a master header file for /test                                       */
/*                                                                                               */
/* ********************************************************************************************* */

#ifndef MC_TEST_H
#define MC_TEST_H

#include "mc_test_assert.h"

/* Include each Moduel after this point */
#include "mc_hash.h"
#include "mc_type.h"
#include "mc_stack.h"
#include "mc_test_hash.h"
#include "mc_test_type.h"
#include "mc_test_stack.h"

/**
 * \brief Run All Tests runs every module that has defined unit tests.
 */
//void Run_All_Tests(void);

#endif
