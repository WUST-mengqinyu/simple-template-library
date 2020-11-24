//
// Created by badcw on 2020/11/23.
//

#ifndef SIMPLE_TEMPLATE_LIBRARY_ALLOC_H
#define SIMPLE_TEMPLATE_LIBRARY_ALLOC_H

#pragma once

#include <cstdlib>
#include <err.h>
#include "__config.h"

_LIB_BEGIN_NAMESPACE_STL

extern const unsigned int POINTER_SIZE = sizeof(void *);
extern const int MIN_ALLOC = 5;
typedef void *memory_resource;

// use malloc to get Memory resource from sys.
static memory_resource MEMORY_POOL = malloc(MIN_ALLOC);

#define __STL_NOW_USE sizeof(MEMORY_POOL)

#if EQUAL(_LIB_STL_VERSION, 1)
void reAlloc(int new_size = -1) {
    int sz_now = __STL_NOW_USE;
    memory_resource __tmp = malloc(sz_now);

    // use builtin memcpy to copy char info.
    __builtin_memcpy(__tmp, MEMORY_POOL, sz_now);
    if (new_size == -1) {
        free(MEMORY_POOL);
        if (sz_now > 100000000) {
        }
        MEMORY_POOL = malloc(sz_now << 1);
    }
}
#endif

template<typename T>
class alloc {
    alloc(int _sz = 0);
};

template<typename T>
alloc<T>::alloc(int _sz) {
}

_LIB_END_NAMESPACE_STL

#endif //SIMPLE_TEMPLATE_LIBRARY_ALLOC_H
