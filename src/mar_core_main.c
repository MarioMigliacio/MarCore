/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mar_core_main.c                                                                        */
/* \brief: Entry point for the application                                                       */
/*                                                                                               */
/* \Expects: mar_core definitions are defined and linked properly                                */
/*                                                                                               */
/* ********************************************************************************************* */

#include "mar_core_type.h"
#include <stdio.h>   // printf [remove later]

/*
 * \brief main application entry point
 *
 * \details Will probably add support to leverage argc, and argv at some point
 *
 * \param argc: int, count of arguments
 * \param argv: char**, array of input commands
 * 
 * \return u32: status code if relevent
 */
int main(int argc, char* argv[]) 
{
    u8 small = 98;

    printf("%d\n", small);

    return 0;
}