//
// Created by rhys on 02/09/24.
//

#ifndef MACROS_H
#define MACROS_H

#ifdef DEBUG
#define dbprintf(...) \
fprintf(stderr, __VA_ARGS__)
#else
#define dbprintf(...)
#endif

#endif //MACROS_H
