//
// Created by mengqinyu on 2020/11/23.
//

#ifndef SIMPLE_TEMPLATE_LIBRARY_BIT_COUNT_H
#define SIMPLE_TEMPLATE_LIBRARY_BIT_COUNT_H

#include <cstdint>
#include <header/kernel_things/__config.h>

_LIB_BEGIN_NAMESPACE_STL

// count a int32 bits of 1
static force_inline int popcount32(unsigned int n);

// count a int64 bits of 1
static force_inline int popcount64(uint64_t n);

static force_inline int CountLeadingZero64Slow(uint64_t n);

static force_inline int CountLeadingZeros64(uint64_t n);

static force_inline int CountLeadingZeros32Slow(uint32_t n);

static force_inline int CountLeadingZeros32(uint32_t n);

static force_inline int CountTrailingZerosNonZero32Slow(uint32_t n);

static force_inline int CountTrailingZerosNonZero32(uint32_t n);

_LIB_END_NAMESPACE_STL

#endif //SIMPLE_TEMPLATE_LIBRARY_BIT_COUNT_H
