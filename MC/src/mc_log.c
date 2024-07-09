/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mc_log.c                                                                               */
/* \brief: Implementation for simple logging utlity                                              */
/*                                                                                               */
/* \Expects: mc_log.h is linked properly and defines interface                                   */
/*                                                                                               */
/* ********************************************************************************************* */

#include "mc_log.h"
#include <stdarg.h>     // va_start
#include <time.h>       // time_t

/**
 * \brief Test file where output will be written
 */
#define LOG_OUTPUT_FILE "last_run_output.txt"

/**
 * \brief File pointer
 */
static FILE *log_output_stream = NULL;

int MC_Log_Init()
{
    if (fopen_s(&log_output_stream, LOG_OUTPUT_FILE, "w") != 0) // Use "w" to overwrite the file each run
    { 
        perror("Failed to open log file");
        
        return -1;
    }

    return 0;
}

void MC_Log_Close()
{
    if (log_output_stream != NULL)
    {
        fclose(log_output_stream);
        log_output_stream = NULL;
    }
}

void MC_Log_Message(LogLevel lvl, const char *format, ...)
{
    if (log_output_stream == NULL)
    {
        return;
    }

    const char *level_str = NULL;
    switch (lvl)
    {
        case MC_LOG_LEVEL_DEBUG:   level_str = "DEBUG"; break;
        case MC_LOG_LEVEL_INFO:    level_str = "INFO"; break;
        case MC_LOG_LEVEL_WARNING: level_str = "WARNING"; break;
        case MC_LOG_LEVEL_ERROR:   level_str = "ERROR"; break;
        default:                level_str = "UNKNOWN"; break;
    }

    // Get current time
    time_t now = time(NULL);
    struct tm t;
    localtime_s(&t, &now);
    char time_str[20];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", &t);

    // Print log message
    va_list args;
    va_start(args, format);
    fprintf(log_output_stream, "[%s] [%s] ", time_str, level_str);
    vfprintf(log_output_stream, format, args);
    fprintf(log_output_stream, "\n");
    va_end(args);
    fflush(log_output_stream);
}
