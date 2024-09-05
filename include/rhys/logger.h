//
// Created by rhys on 02/09/24.
//

#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>

#include "macros.h"

#ifdef RHYS_BUILD_LOGGER

typedef enum log_level {
    LEVEL_DEBUG,
    LEVEL_INFO,
    LEVEL_WARN,
    LEVEL_ERROR,
    LEVEL_CRITICAL
} log_level_t;

FUNC(log_preamble_func_t, int, struct logger* logger, enum log_level);

typedef struct logger {
    int initialised;
    log_preamble_func_t preamble_func;
    enum log_level current_level;
    FILE* out_fh;
} logger_t;

extern struct logger rhys_default_logger;


int clog_init(struct logger* logger);

int clog_set_preamble(struct logger* logger, log_preamble_func_t callback);

int clog(struct logger* logger, enum log_level level, const char *format, ...);

#define log(...) clog(&rhys_default_logger, __VA_ARGS__)
#define log_init() clog_init(&rhys_default_logger)
#define log_set_preamble(callback) clog_set_preamble(&rhys_default_logger, callback)

#endif

#endif //LOGGER_H