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

#define FUNC(name, ret, ...) typedef ret (* name)(__VA_ARGS__)

#endif //MACROS_H
