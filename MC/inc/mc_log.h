/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mc_log.h                                                                               */
/* \brief: Provide simple logging utlity                                                         */
/*                                                                                               */
/* \Expects: No expectations are made prior to type definitions in this file                     */
/*                                                                                               */
/* ********************************************************************************************* */

#ifndef MC_LOG_H
#define MC_LOG_H

#include <stdio.h>  // file ops
#include <stdlib.h> // exit failure

/**
 * \brief Use the Logger to make a DEBUG statement
 */
#define MC_LOG_DEBUG(format, ...)   MC_Log_Message(MC_LOG_LEVEL_DEBUG, format, ##__VA_ARGS__)

/**
 * \brief Use the Logger to make an INFO statement
 */
#define MC_LOG_INFO(format, ...)    MC_Log_Message(MC_LOG_LEVEL_INFO, format, ##__VA_ARGS__)

/**
 * \brief Use the Logger to make a WARNING statement
 */
#define MC_LOG_WARNING(format, ...) MC_Log_Message(MC_LOG_LEVEL_WARNING, format, ##__VA_ARGS__)

/**
 * \brief Use the Logger to make an ERROR statement
 */
#define MC_LOG_ERROR(format, ...)   MC_Log_Message(MC_LOG_LEVEL_ERROR, format, ##__VA_ARGS__)

/**
 * \brief Enumeration for log levels
 */
typedef enum 
{
    MC_LOG_LEVEL_DEBUG,                // \brief Debugging level
    MC_LOG_LEVEL_INFO,                 // \brief Informational level
    MC_LOG_LEVEL_WARNING,              // \brief Warning level
    MC_LOG_LEVEL_ERROR                 // \brief Error level
} LogLevel;

/**
 * \brief Open the LOG_OUTPUT_FILE for write mode
 * \returns int: errorcode -1 to stderr if unable to make log file
 */
int MC_Log_Init();

/**
 * \brief Close the LOG_OUTPUT_FILE
 */
void MC_Log_Close();

/**
 * \brief Log a message with a specific log level
 *
 * \param lvl: LogLevel
 * \param fmt: Format string for printing
 */
void MC_Log_Message(LogLevel lvl, const char *fmt, ...);

#endif
