#ifndef LOGNEST_H
#define LOGNEST_H

#include <stdarg.h>
#include <stdio.h>
#include <time.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Log {
        const char *identifier;
        const char *filename;
} Log;

void log_message(Log *log, const char *level, const char *format, va_list args);

void log_trace(Log *log, const char *format, ...);
void log_warn(Log *log, const char *format, ...);
void log_error(Log *log, const char *format, ...);
void log_debug(Log *log, const char *format, ...);

void get_timestamp(char *buffer, size_t len);

#ifdef __cplusplus
}
#endif

#endif // !LOGNEST_H
