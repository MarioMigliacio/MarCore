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

#include "mar_core_type.h"
#include "mar_core_test_file.h"
#include "mar_core_test_assert.h"

/*
 * \brief Test type Unsigned Max Values Are Expected
 *
 * \details Stress the type definitions and values
 */
void Test_mar_core_type_UnsignedMaxValuesAreExpected(void);

/*
 * \brief Test type Unsigned Overflow Expected
 *
 * \details Stress the type definitions and values
 */
void Test_mar_core_type_UnsignedOverflowExpected(void);

/*
 * \brief Test type Signed Min Values Are Expected
 *
 * \details Stress the type definitions and values
 */
void Test_mar_core_type_SignedMinValuesAreExpected(void);

/*
 * \brief Test type Signed Max Values Are Expected
 *
 * \details Stress the type definitions and values
 */
void Test_mar_core_type_SignedMaxValuesAreExpected(void);

/*
 * \brief Main exposed module for all unit tests of type mario_core_type
 *
 * \details Package all the mar core type unit tests
 */
void Run_Test_Module_Mar_Core_Type(void);

/*
 * \brief Run All Tests runs every module that has defined unit tests.
 */
void Run_All_Tests(void);

#endif
