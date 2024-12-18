#ifndef LOGNEST_H_
#define LOGNEST_H_

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define TIMESTAMP_BUFFER_MAX_SIZE 2048

void _lognest_trace_raw(const char *file, const char *format, ...);
void _lognest_warn_raw(const char *file, const char *format, ...);
void _lognest_error_raw(const char *file, const char *format, ...);
void _lognest_debug_raw(const char *file, const char *format, ...);

#define lognest_trace(format, ...) _lognest_trace_raw(LOGNEST_FILE, format, ##__VA_ARGS__)
#define lognest_warn(format, ...) _lognest_warn_raw(LOGNEST_FILE, format, ##__VA_ARGS__)
#define lognest_error(format, ...) _lognest_error_raw(LOGNEST_FILE, format, ##__VA_ARGS__)
#define lognest_debug(format, ...) _lognest_debug_raw(LOGNEST_FILE, format, ##__VA_ARGS__)

void lognest_to_file(const char *file, const char *level, const char *format, va_list args);

void get_timestamp(char *buffer, size_t len);

#ifdef LOGNEST_IMPLEMENTATION

inline void get_timestamp(char *buffer, size_t len) {

    if (buffer == NULL || len > TIMESTAMP_BUFFER_MAX_SIZE) {
        fprintf(stderr, "LogNest: timestamp buffer, was too small\n");
        return;
    }

    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    if (t == NULL) {
        fprintf(stderr, "LogNest: failed to get localtime\n");
        return;
    }

    strftime(buffer, len, "[%y/%m/%d][%H:%M:%S]", t);
}

void lognest_to_file(const char *file, const char *level, const char *format, va_list args) {

    if (file == NULL) {
        fprintf(stderr, "LogNest: filename was recieved as NULL or invalid: value: %s\n", file);
        return;
    }

    FILE *log_file = fopen(file, "a");
    if (log_file == NULL) {
        fprintf(stderr, "LogNest: error trying to open file %s", file);
        return;
    }

    char timestamp[TIMESTAMP_BUFFER_MAX_SIZE] = {0};
    get_timestamp(timestamp, TIMESTAMP_BUFFER_MAX_SIZE);

    fprintf(log_file, "%s%s: ", timestamp, level);

    vfprintf(log_file, format, args);

    fprintf(log_file, "\n");

    fclose(log_file);
}

void _lognest_trace_raw(const char *file, const char *format, ...) {

    va_list args;
    va_start(args, format);
    lognest_to_file(file, "[LOG]  ", format, args);

    va_end(args);
}

void _lognest_warn_raw(const char *file, const char *format, ...) {

    va_list args;
    va_start(args, format);
    lognest_to_file(file, "[WARN] ", format, args);

    va_end(args);
}

void _lognest_error_raw(const char *file, const char *format, ...) {

    va_list args;
    va_start(args, format);
    lognest_to_file(file, "[ERROR]", format, args);

    va_end(args);
}

void _lognest_debug_raw(const char *file, const char *format, ...) {

    va_list args;
    va_start(args, format);
    lognest_to_file(file, "[DEBUG]", format, args);

    va_end(args);
}

#endif // LOGNEST_IMPLEMENTATION

#endif // !LOGNEST_H_
