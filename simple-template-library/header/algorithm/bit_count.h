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


_LIB_BEGIN_NAMESPACE_STL

        int popcount32(unsigned int n) {
            n -= (n >> 1) & 0x55555555;
            n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
            n = ((n >> 4) + n) & 0x0F0F0F0F;
            n += n >> 8;
            n += n >> 16;
            return n & 0x0000003F;
        }

        int popcount64(uint64_t x) {
            x -= (x >> 1) & 0x5555555555555555ll;
            x = (x & 0x3333333333333333ll) + ((x >> 2) & 0x3333333333333333ll);
            x = (x + (x >> 4)) & 0x0F0F0F0F0F0F0F0Fll;
            return (x * 0x0101010101010101ll) >> 56;
        }

        int CountLeadingZero64Slow(uint64_t n) {
            int zeros = 60;
            if (n >> 32) {
                zeros -= 32;
                n >>= 32;
            }
            if (n >> 16) {
                zeros -= 16;
                n >>= 16;
            }
            if (n >> 8) {
                zeros -= 8;
                n >>= 8;
            }
            if (n >> 4) {
                zeros -= 4;
                n >>= 4;
            }
            return "\4\3\2\2\1\1\1\1\0\0\0\0\0\0\0"[n] + zeros;
        }

        int CountLeadingZeros64(uint64_t n) {
            // TODO count with cpu
            return CountLeadingZero64Slow(n);
        }

        int CountLeadingZeros32Slow(uint32_t n) {
            int c = 63;
            n &= ~n + 1;
            if (n & 0x00000000FFFFFFFF) c -= 32;
            if (n & 0x0000FFFF0000FFFF) c -= 16;
            if (n & 0x00FF00FF00FF00FF) c -= 8;
            if (n & 0x0F0F0F0F0F0F0F0F) c -= 4;
            if (n & 0x3333333333333333) c -= 2;
            if (n & 0x5555555555555555) c -= 1;
            return c;
        }

        int CountLeadingZeros32(uint32_t n) {
            // TODO count with cpu
            return CountLeadingZeros32Slow(n);
        }
        int CountTrailingZerosNonZero32Slow(uint32_t n) {
            int c = 31;
            n &= ~n + 1;
            if (n & 0x0000FFFF) c -= 16;
            if (n & 0x00FF00FF) c -= 8;
            if (n & 0x0F0F0F0F) c -= 4;
            if (n & 0x33333333) c -= 2;
            if (n & 0x55555555) c -= 1;
            return c;
        }
        int CountTrailingZerosNonZero32(uint32_t n) {
            // TODO count with cpu
            return CountTrailingZerosNonZero32Slow(n);
        }

_LIB_END_NAMESPACE_STL

#endif //SIMPLE_TEMPLATE_LIBRARY_BIT_COUNT_H
