//
// Created by rhys on 02/09/24.
//

#include "logger.h"

#include <stdarg.h>
#include <time.h>

struct logger rhys_default_logger = {.initialised = 0};

int log_preamble(struct logger* logger, enum log_level level);

#define check_logger(logger) if(logger == NULL || logger->initialised != 1) { \
    eprintf("Error: logger uninitialised on line: %d\n", __LINE__); \
    return 1; \
}

int clog_init(struct logger* logger) {
    *logger = (struct logger) {
        .initialised = 1,
        .current_level = LEVEL_INFO,
        .out_fh =  stderr,
        .preamble_func = log_preamble
    };

    return 0;
}

int log_preamble(struct logger* logger, enum log_level level) {
    check_logger(logger);

    time_t current_time;
    time(&current_time);

    struct tm *time_info = localtime(&current_time);

    char time_str[32];
    strftime(time_str, 32, "%y/%m/%d %H:%M:%S", time_info);

    fprintf(logger->out_fh, "[%s] => ", time_str);

    return 0;
}

int clog_set_preamble(struct logger* logger, log_preamble_func_t callback) {
    check_logger(logger);

    logger->preamble_func = callback;

    return 0;
}

int clog(struct logger* logger, enum log_level level, const char *format, ...) {
    check_logger(logger);

    if(level < logger->current_level)
        return 1;

    va_list args;
    va_start(args, format);

    logger->preamble_func(logger, level);
    vfprintf(stderr, format, args);

    va_end(args);

    return 0;
}
