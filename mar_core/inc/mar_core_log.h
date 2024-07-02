/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mar_core_log.h                                                                         */
/* \brief: Provide simple logging utlity                                                         */
/*                                                                                               */
/* \Expects: No expectations are made prior to type definitions in this file                     */
/*                                                                                               */
/* ********************************************************************************************* */

#ifndef MAR_CORE_LOG_H
#define MAR_CORE_LOG_H

#include <stdio.h>  // file ops
#include <stdlib.h> // exit failure

/*
 * \brief Use the Logger to make a DEBUG statement
 */
#define LOG_DEBUG(format, ...)   log_message(LOG_LEVEL_DEBUG, format, ##__VA_ARGS__)

/*
 * \brief Use the Logger to make an INFO statement
 */
#define LOG_INFO(format, ...)    log_message(LOG_LEVEL_INFO, format, ##__VA_ARGS__)

/*
 * \brief Use the Logger to make a WARNING statement
 */
#define LOG_WARNING(format, ...) log_message(LOG_LEVEL_WARNING, format, ##__VA_ARGS__)

/*
 * \brief Use the Logger to make an ERROR statement
 */
#define LOG_ERROR(format, ...)   log_message(LOG_LEVEL_ERROR, format, ##__VA_ARGS__)

/*
 * \brief Enumeration for log levels
 */
typedef enum {
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARNING,
    LOG_LEVEL_ERROR
} LogLevel;

/*
 * \brief Open the LOG_OUTPUT_FILE for write mode
 */
int log_init();

/*
 * \brief Close the LOG_OUTPUT_FILE
 */
void log_close();

/*
 * \brief Log a message with a specific log level
 *
 * \param lvl LogLevel
 * \param fmt Format string for printing
 */
void log_message(LogLevel lvl, const char *fmt, ...);

#endif
