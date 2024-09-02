//
// Created by rhys on 02/09/24.
//

#include "logger.h"

#include "rhys.h"

#include <stdarg.h>
#include <time.h>

static void log_preamble(enum log_level level);

#define log_fh stderr

static log_preamble_func_t log_preamble_func = log_preamble;
static enum log_level current_level;


static void log_preamble(enum log_level level) {
    time_t current_time;
    time(&current_time);

    struct tm *time_info = localtime(&current_time);

    char time_str[32];
    strftime(time_str, 32, "%y/%m/%d %H:%M:%S", time_info);

    fprintf(log_fh, "[%s] => ", time_str);
}

void log_set_preamble(log_preamble_func_t callback) {
    log_preamble_func = callback;
}

void log(enum log_level level, const char *format, ...) {
    if(level <= current_level)
        return;

    va_list args;
    va_start(args, format);

    log_preamble_func(level);
    vfprintf(stderr, format, args);

    va_end(args);
}
