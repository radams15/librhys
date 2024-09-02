//
// Created by rhys on 02/09/24.
//

#ifndef LOGGER_H
#define LOGGER_H

#include "macros.h"

typedef enum log_level {
    LEVEL_DEBUG,
    LEVEL_INFO,
    LEVEL_WARN,
    LEVEL_ERROR,
    LEVEL_CRITICAL
} log_level_t;

FUNC(log_preamble_func_t, void, enum log_level);

void log_set_preamble(log_preamble_func_t callback);

void log(enum log_level level, const char *format, ...);

#endif //LOGGER_H
