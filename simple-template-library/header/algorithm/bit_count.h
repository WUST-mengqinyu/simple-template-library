//
// Created by mengqinyu on 2020/11/23.
//

#ifndef SIMPLE_TEMPLATE_LIBRARY_BIT_COUNT_H
#define SIMPLE_TEMPLATE_LIBRARY_BIT_COUNT_H

#include <cstdint>
#include <header/kernel_things/__config.h>

_LIB_BEGIN_NAMESPACE_STL

// count a int32 bits of 1
        int popcount32(unsigned int n);

// count a int64 bits of 1
        int popcount64(uint64_t n);

        int CountLeadingZero64Slow(uint64_t n);

        int CountLeadingZeros64(uint64_t n);

        int CountLeadingZeros32Slow(uint32_t n);

        int CountLeadingZeros32(uint32_t n);

        int CountTrailingZerosNonZero32Slow(uint32_t n);

        int CountTrailingZerosNonZero32(uint32_t n);

_LIB_END_NAMESPACE_STL

#endif //SIMPLE_TEMPLATE_LIBRARY_BIT_COUNT_H
