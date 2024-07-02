/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: test_main.c                                                                            */
/* \brief: Main entry for test run                                                               */
/*                                                                                               */
/* \Expects: mar_core_test definitions are defined and linked properly                           */
/*                                                                                               */
/* ********************************************************************************************* */

#include "mar_core_test.h"
#include "mar_core_log.h"

/*
 * \brief main application entry point
 *
 * \details Will probably add support to leverage argc, and argv at some point
 *
 * \param argc: int, count of arguments
 * \param argv: char**, array of input commands
 * 
 * \return int: status code if relevent
 */
int main(int argc, char* argv[])
{
    Run_All_Tests();

    return 0;
}
