#include "lognest.h"
#include <stdarg.h>
#include <stdio.h>
#include <time.h>

void get_timestamp(char *buffer, size_t len) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    strftime(buffer, len, "[%y/%m/%d][%H:%M:%S]", t);
}

void log_message(Log *log, const char *level, const char *format, va_list args) {

    FILE *file = fopen(log->filename, "a"); // a = append, apparently
    if (file == NULL) {
        perror("ERROR OPPENING FILE");
        return;
    }

    char timestamp[100];
    get_timestamp(timestamp, sizeof(timestamp));

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
