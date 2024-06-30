/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mar_core_test.h                                                                        */
/* \brief: Header collection with function prototypes for testing                                */
/*                                                                                               */
/* \Expects: mar_core_test definitions are defined and linked properly                           */
/*                                                                                               */
/* ********************************************************************************************* */

#ifndef MAR_CORE_TEST_H
#define MAR_CORE_TEST_H

/* Add test modules as you develop them here */
#include "mar_core_test_file.h"
#include "mar_core_test_assert.h"

void Test_mar_core_type_UnsignedMaxValuesAreExpected(void);

void Run_All_Tests(void);

#endif
