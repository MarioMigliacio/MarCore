/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: test_main.c                                                                            */
/* \brief: Main entry for test run                                                               */
/*                                                                                               */
/* \Expects: mc_test definitions are defined and linked properly                                 */
/*                                                                                               */
/* ********************************************************************************************* */

#include "mc_test.h"

/**
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

void Run_All_Tests(void)
{
    OPEN_TEST_OUTPUT_FILE("w"); // start with a fresh file
    CLOSE_TEST_OUTPUT_FILE();   // each module will handle appending from here on their own

    /* Add each Run_Test_Module here */
    Test_MC_Module_Type();
    Test_MC_Module_Hash();
    Test_MC_Module_Stack();
}
