#include "lognest.h"
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define TIMESTAMP_BUFFER_MAX_SIZE 2048
/*#define LOG_BUFFER_MAX_SIZE 512*/

void get_timestamp(char *buffer, size_t len) {

    if (buffer == NULL || len > TIMESTAMP_BUFFER_MAX_SIZE) {
        fprintf(stderr, "Timestamp Buffer was too small!\n");
        return;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    if (t == NULL) {
        fprintf(stderr, "Failed to get localtime!\n");
        return;
    }

    strftime(buffer, len, "[%y/%m/%d][%H:%M:%S]", t);
}

void log_message(Log *log, const char *level, const char *format, va_list args) {

    if (log == NULL || log->filename == NULL || level == NULL || format == NULL) {
        fprintf(stderr, "Something was NULL on log_message()\n");
        return;
    }

    FILE *file = fopen(log->filename, "a"); // a = append, apparently
    if (file == NULL) {
        fprintf(stderr, "Error trying to log to file, %s\n", strerror(errno));
        return;
    }

    char timestamp[TIMESTAMP_BUFFER_MAX_SIZE] = {0};
    get_timestamp(timestamp, TIMESTAMP_BUFFER_MAX_SIZE);

    fprintf(file, "%s%s%s:", timestamp, log->identifier, level);

    vfprintf(file, format, args);

    fprintf(file, "\n");

    fclose(file);
}

void log_trace(Log *log, const char *format, ...) {
    va_list args;

    va_start(args, format);

    log_message(log, "[LOG]", format, args);

    va_end(args);
}

void log_warn(Log *log, const char *format, ...) {
    va_list args;

    va_start(args, format);

    log_message(log, "[WARN]", format, args);

    va_end(args);
}

void log_error(Log *log, const char *format, ...) {
    va_list args;

    va_start(args, format);

    log_message(log, "[ERROR]", format, args);

    va_end(args);
}

void log_debug(Log *log, const char *format, ...) {
    va_list args;

    va_start(args, format);

    log_message(log, "[DEBUG]", format, args);

    va_end(args);
}
