//
// Created by mengqinyu on 2020/11/25.
//

#include <header/data_structure/numeric/int128.h>
#include <header/kernel_things/__config.h>
#include <header/algorithm/bit_count.h>

#include <cassert>
#include <iomanip>
#include <ostream>  // NOLINT(readability/streams)
#include <sstream>
#include <string>
#include <type_traits>

_LIB_BEGIN_NAMESPACE_STL
using namespace __INTERNAL;

const uint128 int128max = MakeUint128(
        std::numeric_limits<uint64_t>::max(), std::numeric_limits<uint64_t>::max());

namespace {
    force_inline int Fls128(uint128 n) {
        if (uint64_t hi = Uint128High64(n)) {
            return 127 - stl::CountLeadingZeros64(hi);
        }
        const int64_t low = Uint128Low64(n);
        return 63 - stl::CountLeadingZeros64(low);
    }

    // dividend = divisor * ret + remainder
    // remainder < divisor
    force_inline void DivMod(uint128 dividend, uint128 divisor,
                             uint128* ret, uint128* remainder) {
        // while divisor equal to zero, throw a fail
        assert(divisor != 0);
        if (divisor > dividend) {
            *ret = 0;
            *remainder = dividend;
            return;
        }
        if (divisor == dividend) {
            *ret = 1;
            *remainder = 0;
            return;
        }

        uint128 denominator = divisor;
        uint128 quotient = 0;

        const int shift = Fls128(dividend) - Fls128(denominator);
        denominator <<= shift;

        // quick pow
        for (int i = 0; i <= shift; ++i) {
            quotient <<= 1;
            if (dividend >= denominator) {
                dividend -= denominator;
                quotient |= 1;
            }
            denominator >>= 1;
        }

        *ret = quotient;
        *remainder = dividend;
    }
}

_LIB_END_NAMESPACE_STL