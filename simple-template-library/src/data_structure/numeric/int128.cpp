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
#include <header/data_structure/base_ds.h>
#include <iostream>

_LIB_BEGIN_NAMESPACE_STL

        namespace __INTERNAL {
            const uint128 int128max = __INTERNAL::MakeUint128(
                    std::numeric_limits<uint64_t>::max(), std::numeric_limits<uint64_t>::max());

            namespace {
                int Fls128(uint128 n) {
                    if (uint64_t hi = Uint128High64(n)) {
                        return 127 - stl::CountLeadingZeros64(hi);
                    }
                    const int64_t low = Uint128Low64(n);
                    return 63 - stl::CountLeadingZeros64(low);
                }

                // dividend = divisor * ret + remainder
                // remainder < divisor
                void DivMod(uint128 dividend, uint128 divisor,
                                         uint128 *ret, uint128 *remainder) {
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

                template<typename T>
                uint128 MakeUint128FromFloat(T v) {
                    static_assert(std::is_floating_point<T>::value, "");
                    assert(std::isfinite(v) && v > -1 &&
                           (std::numeric_limits<T>::max_exponent <= 128 ||
                            v < std::ldexp(static_cast<T>(1), 128)));
                    if (v >= std::ldexp(static_cast<T>(1), 64)) {
                        uint64_t hi = static_cast<uint64_t>(std::ldexp(v, -64));
                        uint64_t lo = static_cast<uint64_t>(v - std::ldexp(static_cast<T>(hi), 64));
                        return __INTERNAL::MakeUint128(hi, lo);
                    }
                    return __INTERNAL::MakeUint128(0, static_cast<uint64_t>(v));
                }
            }


            uint128::uint128(float v) : uint128(MakeUint128FromFloat(v)) {}
            uint128::uint128(double v) : uint128(MakeUint128FromFloat(v)) {}
            uint128::uint128(long double v) : uint128(MakeUint128FromFloat(v)) {}

            uint128 operator/(uint128 lhs, uint128 rhs) {
#ifdef STL_HAVE_INTRINSIC_INT128
                return static_cast<unsigned __int128>(lhs) /
                       static_cast<unsigned __int128>(rhs);
#else
                uint128 quotient = 0;
                uint128 remainder = 0;
                DivMod(lhs, rhs, &quotient, &remainder);
                return quotient;
#endif
            }

            uint128 operator%(uint128 lhs, uint128 rhs) {
#ifdef STL_HAVE_INTRINSIC_INT128
                return static_cast<unsigned __int128>(lhs) %
                       static_cast<unsigned __int128>(rhs);
#else
                uint128 quotient = 0;
                uint128 remainder = 0;
                DivMod(lhs, rhs, &quotient, &remainder);
                return remainder;
#endif
            }

            namespace {
                std::string Uint128ToFormattedString(uint128 v, std::ios_base::fmtflags flags) {
                    uint128 div;
                    int div_base_log;
                    switch (flags & std::ios::basefield) {
                        case std::ios::hex:
                            div = 0x1000000000000000;
                            div_base_log = 15;
                            break;
                        case std::ios::oct:
                            div = 01000000000000000000000;
                            div_base_log = 21;
                            break;
                        case std::ios::dec:
                            div = 10000000000000000000u;
                            div_base_log = 19;
                            break;
                        default:
                            std::cerr << "fail to check ios fmt" << std::endl;
                            return "";
                    }
                    std::ostringstream os;
                    std::ios_base::fmtflags copy_mask =
                            std::ios::basefield | std::ios::showbase | std::ios::uppercase;
                    os.setf(flags & copy_mask, copy_mask);
                    uint128 high = v;
                    uint128 low;
                    DivMod(high, div, &high, &low);
                    uint128 mid;
                    DivMod(high, div, &high, &mid);
                    if (Uint128Low64(high) != 0) {
                        os << Uint128Low64(high);
                        os << std::noshowbase << std::setfill('0') << std::setw(div_base_log);
                        os << Uint128Low64(mid);
                        os << std::setw(div_base_log);
                    } else if (Uint128Low64(mid) != 0) {
                        os << Uint128Low64(mid);
                        os << std::noshowbase << std::setfill('0') << std::setw(div_base_log);
                    }
                    os << Uint128Low64(low);
                    return os.str();
                }
            }


            std::ostream &operator<<(std::ostream &os, uint128 v) {
                std::ios_base::fmtflags flags = os.flags();
                std::string rep = Uint128ToFormattedString(v, flags);

                // Add the requisite padding.
                std::streamsize width = os.width(0);
                if (static_cast<size_t>(width) > rep.size()) {
                    std::ios::fmtflags adjustfield = flags & std::ios::adjustfield;
                    if (adjustfield == std::ios::left) {
                        rep.append(width - rep.size(), os.fill());
                    } else if (adjustfield == std::ios::internal &&
                               (flags & std::ios::showbase) &&
                               (flags & std::ios::basefield) == std::ios::hex && v != 0) {
                        rep.insert(2, width - rep.size(), os.fill());
                    } else {
                        rep.insert(0, width - rep.size(), os.fill());
                    }
                }

                return os << rep;
            }

            namespace {

                uint128 UnsignedAbsoluteValue(int128 v) {
                    // Cast to uint128 before possibly negating because -Int128Min() is undefined.
                    return Int128High64(v) < 0 ? -uint128(v) : uint128(v);
                }

            }  // namespace

            std::ostream &operator<<(std::ostream &os, int128 v) {
                std::ios_base::fmtflags flags = os.flags();
                std::string rep;

                // Add the sign if needed.
                bool print_as_decimal =
                        (flags & std::ios::basefield) == std::ios::dec ||
                        (flags & std::ios::basefield) == std::ios_base::fmtflags();
                if (print_as_decimal) {
                    if (Int128High64(v) < 0) {
                        rep = "-";
                    } else if (flags & std::ios::showpos) {
                        rep = "+";
                    }
                }

                rep.append(Uint128ToFormattedString(
                        print_as_decimal ? UnsignedAbsoluteValue(v) : uint128(v), os.flags()));

                // Add the requisite padding.
                std::streamsize width = os.width(0);
                if (static_cast<size_t>(width) > rep.size()) {
                    switch (flags & std::ios::adjustfield) {
                        case std::ios::left:
                            rep.append(width - rep.size(), os.fill());
                            break;
                        case std::ios::internal:
                            if (print_as_decimal && (rep[0] == '+' || rep[0] == '-')) {
                                rep.insert(1, width - rep.size(), os.fill());
                            } else if ((flags & std::ios::basefield) == std::ios::hex &&
                                       (flags & std::ios::showbase) && v != 0) {
                                rep.insert(2, width - rep.size(), os.fill());
                            } else {
                                rep.insert(0, width - rep.size(), os.fill());
                            }
                            break;
                        default:  // std::ios::right
                            rep.insert(0, width - rep.size(), os.fill());
                            break;
                    }
                }

                return os << rep;
            }
        }

_LIB_END_NAMESPACE_STL

namespace std {
    constexpr bool numeric_limits<stl::uint128>::is_specialized;
    constexpr bool numeric_limits<stl::uint128>::is_signed;
    constexpr bool numeric_limits<stl::uint128>::is_integer;
    constexpr bool numeric_limits<stl::uint128>::is_exact;
    constexpr bool numeric_limits<stl::uint128>::has_infinity;
    constexpr bool numeric_limits<stl::uint128>::has_quiet_NaN;
    constexpr bool numeric_limits<stl::uint128>::has_signaling_NaN;
    constexpr float_denorm_style numeric_limits<stl::uint128>::has_denorm;
    constexpr bool numeric_limits<stl::uint128>::has_denorm_loss;
    constexpr float_round_style numeric_limits<stl::uint128>::round_style;
    constexpr bool numeric_limits<stl::uint128>::is_iec559;
    constexpr bool numeric_limits<stl::uint128>::is_bounded;
    constexpr bool numeric_limits<stl::uint128>::is_modulo;
    constexpr int numeric_limits<stl::uint128>::digits;
    constexpr int numeric_limits<stl::uint128>::digits10;
    constexpr int numeric_limits<stl::uint128>::max_digits10;
    constexpr int numeric_limits<stl::uint128>::radix;
    constexpr int numeric_limits<stl::uint128>::min_exponent;
    constexpr int numeric_limits<stl::uint128>::min_exponent10;
    constexpr int numeric_limits<stl::uint128>::max_exponent;
    constexpr int numeric_limits<stl::uint128>::max_exponent10;
    constexpr bool numeric_limits<stl::uint128>::traps;
    constexpr bool numeric_limits<stl::uint128>::tinyness_before;

    constexpr bool numeric_limits<stl::int128>::is_specialized;
    constexpr bool numeric_limits<stl::int128>::is_signed;
    constexpr bool numeric_limits<stl::int128>::is_integer;
    constexpr bool numeric_limits<stl::int128>::is_exact;
    constexpr bool numeric_limits<stl::int128>::has_infinity;
    constexpr bool numeric_limits<stl::int128>::has_quiet_NaN;
    constexpr bool numeric_limits<stl::int128>::has_signaling_NaN;
    constexpr float_denorm_style numeric_limits<stl::int128>::has_denorm;
    constexpr bool numeric_limits<stl::int128>::has_denorm_loss;
    constexpr float_round_style numeric_limits<stl::int128>::round_style;
    constexpr bool numeric_limits<stl::int128>::is_iec559;
    constexpr bool numeric_limits<stl::int128>::is_bounded;
    constexpr bool numeric_limits<stl::int128>::is_modulo;
    constexpr int numeric_limits<stl::int128>::digits;
    constexpr int numeric_limits<stl::int128>::digits10;
    constexpr int numeric_limits<stl::int128>::max_digits10;
    constexpr int numeric_limits<stl::int128>::radix;
    constexpr int numeric_limits<stl::int128>::min_exponent;
    constexpr int numeric_limits<stl::int128>::min_exponent10;
    constexpr int numeric_limits<stl::int128>::max_exponent;
    constexpr int numeric_limits<stl::int128>::max_exponent10;
    constexpr bool numeric_limits<stl::int128>::traps;
    constexpr bool numeric_limits<stl::int128>::tinyness_before;
}