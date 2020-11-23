//
// Created by mengqinyu on 2020/11/23.
//

#ifndef SIMPLE_TEMPLATE_LIBRARY_BIT_COUNT_H
#define SIMPLE_TEMPLATE_LIBRARY_BIT_COUNT_H

#include <cstdint>
#include <header/kernel_things/__config.h>

// count a int32 bits of 1
static force_inline int popcount32(unsigned int n);

// count a int64 bits of 1
static force_inline int popcount64(uint64_t n);

#endif //SIMPLE_TEMPLATE_LIBRARY_BIT_COUNT_H
