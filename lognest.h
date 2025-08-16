/* Copyright 2024 LeaoMartelo2 (https://github.com/LeaoMartelo2)

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the “Software”), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. */

#ifndef LOGNEST_H_
#define LOGNEST_H_

#define LOGNEST_VERSION "2.1.5"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/* If LOGNEST_FILE is not defined before the include, default to latest.log at the execution path */
#ifndef LOGNEST_FILE
#define LOGNEST_FILE "latest.log"
#endif // LOGNEST_FILE

// default all functions to static inline, so they are stripped from the binary if unused
#ifndef LOGNEST_API
#define LOGNEST_API static inline
#endif // LOGNEST_API

// @LOG PREFIXEX

#ifndef LOGNEST_TRACE_PREFIX
#define LOGNEST_TRACE_PREFIX "[LOG]  "
#endif // LOGNEST_TRACE_PREFIX

#ifndef LOGNEST_WARN_PREFIX
#define LOGNEST_WARN_PREFIX "[WARN]"
#endif // LOGNEST_WARN_PREFIX

#ifndef  LOGNEST_ERROR_PREFIX
#define LOGNEST_ERROR_PREFIX "[ERROR]"
#endif // LOGNEST_ERROR_PREFIX

#ifndef LOGNEST_DEBUG_PREFIX
#define LOGNEST_DEBUG_PREFIX "[DEBUG]"
#endif // LOGNEST_DEBUG_PREFIX

#define TIMESTAMP_BUFFER_MAX_SIZE 2048

LOGNEST_API void _lognest_trace_raw(const char *file, const char *format, ...);
LOGNEST_API void _lognest_warn_raw(const char *file, const char *format, ...);
LOGNEST_API void _lognest_error_raw(const char *file, const char *format, ...);
LOGNEST_API void _lognest_debug_raw(const char *file, const char *format, ...);

#define lognest_trace(...) _lognest_trace_raw(LOGNEST_FILE, __VA_ARGS__)
#define lognest_warn(...) _lognest_warn_raw(LOGNEST_FILE, __VA_ARGS__)
#define lognest_error(...) _lognest_error_raw(LOGNEST_FILE, __VA_ARGS__)
#define lognest_debug(...) _lognest_debug_raw(LOGNEST_FILE, __VA_ARGS__)

LOGNEST_API void lognest_to_file(const char *file, const char *level, const char *format, va_list args);

LOGNEST_API void _lognest_get_timestamp(char *buffer, size_t len);

#ifdef __cplusplus
}
#endif // __cplusplus
 

// DO NOT FORGET TO COMMENT THIS OUT BEFORE PUSHING
#define LOGNEST_IMPLEMENTATION

#ifdef LOGNEST_IMPLEMENTATION

LOGNEST_API void _lognest_get_timestamp(char *buffer, size_t len) {

    if (buffer == NULL || len > TIMESTAMP_BUFFER_MAX_SIZE) {
	// just to make sure, 2kb for a date is way too much
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

LOGNEST_API void lognest_to_file(const char *file, const char *level, const char *format, va_list args) {

    if (file == NULL) {
        fprintf(stderr, "LogNest: filename was recieved as NULL or invalid: value: %s\n", file);
        return;
    }

    FILE *log_file = fopen(file, "a");
    if (log_file == NULL) {
        fprintf(stderr, "LogNest: error trying to open file %s", file);
        return;
    }

    /* disable timestamp */
#ifndef LOGNEST_DISABLE_TIMESTAMP

    char timestamp[TIMESTAMP_BUFFER_MAX_SIZE] = {0};
    _lognest_get_timestamp(timestamp, TIMESTAMP_BUFFER_MAX_SIZE);

    fprintf(log_file, "%s", timestamp);

#endif // LOGNEST_DISABLE_TIMESTAMP

    fprintf(log_file, "%s: ", level);

    vfprintf(log_file, format, args);

    fprintf(log_file, "\n");

    fclose(log_file);
}

LOGNEST_API void _lognest_trace_raw(const char *file, const char *format, ...) {

#ifdef LOGNEST_DISABLE_TRACE
    return;
#endif // LOGNEST_DISABLE_TRACE

    va_list args;
    va_start(args, format);
    lognest_to_file(file, LOGNEST_TRACE_PREFIX, format, args);

    va_end(args);
}

LOGNEST_API void _lognest_warn_raw(const char *file, const char *format, ...) {

#ifdef LOGNEST_DISABLE_WARN
    return;
#endif // LOGNEST_DISABLE_WARN

    va_list args;
    va_start(args, format);
    lognest_to_file(file, LOGNEST_WARN_PREFIX, format, args);

    va_end(args);
}

LOGNEST_API void _lognest_error_raw(const char *file, const char *format, ...) {

#ifdef LOGNEST_DISABLE_ERROR
    return;
#endif // LOGNEST_DISABLE_ERROR

    va_list args;
    va_start(args, format);
    lognest_to_file(file, LOGNEST_WARN_PREFIX, format, args);

    va_end(args);
}

LOGNEST_API void _lognest_debug_raw(const char *file, const char *format, ...) {

#ifdef LOGNEST_DISABLE_DEBUG
    return;
#endif // LOGNEST_DISABLE_DEBUG

    va_list args;
    va_start(args, format);
    lognest_to_file(file, LOGNEST_DEBUG_PREFIX, format, args);

    va_end(args);
}

#endif // LOGNEST_IMPLEMENTATION

#endif // !LOGNEST_H_
