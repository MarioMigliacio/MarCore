/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: test_main.c                                                                            */
/* \brief: Main entry for test run                                                               */
/*                                                                                               */
/* \Expects: mar_core_test definitions are defined and linked properly                           */
/*                                                                                               */
/* ********************************************************************************************* */

#include "mar_core_test.h"      // Example of a test module
#include "mar_core_log.h"       // TODO:

/*
 * \brief main application entry point
 *
 * \details Will probably add support to leverage argc, and argv at some point
 *
 * \param argc: count of arguments
 * \param argv: array of input commands
 * 
 * \return int: status code
 */
int main(int argc, char* argv[])
{
    Run_All_Tests();

    return 0;
}
