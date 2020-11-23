//
// Created by mengqinyu on 2020/11/23.
//

#include "header/algorithm/bit_count.h"

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