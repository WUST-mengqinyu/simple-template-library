//
// Created by mengqinyu on 2020/11/25.
//

#ifndef SIMPLE_TEMPLATE_LIBRARY_INT128_H
#define SIMPLE_TEMPLATE_LIBRARY_INT128_H

#include <header/kernel_things/__config.h>
#include <ostream>
#include <limits>
#include <cmath>

_LIB_BEGIN_NAMESPACE_STL
// uint128 function
        namespace __INTERNAL {

            // first define to write uint128
            class int128;

            class
#if defined(STL_HAVE_INTRINSIC_INT128)
            alignas(unsigned __int128)
#endif  // STL_HAVE_INTRINSIC_INT128
            uint128 {
            public:
                uint128() = default;

                // Constructors from arithmetic types
                constexpr uint128(int v);                 // NOLINT(runtime/explicit)
                constexpr uint128(unsigned int v);        // NOLINT(runtime/explicit)
                constexpr uint128(long v);                // NOLINT(runtime/int)
                constexpr uint128(unsigned long v);       // NOLINT(runtime/int)
                constexpr uint128(long long v);           // NOLINT(runtime/int)
                constexpr uint128(unsigned long long v);  // NOLINT(runtime/int)
#ifdef STL_HAVE_INTRINSIC_INT128
                constexpr uint128(__int128 v);           // NOLINT(runtime/explicit)
                constexpr uint128(unsigned __int128 v);  // NOLINT(runtime/explicit)
#endif  // STL_HAVE_INTRINSIC_INT128
                constexpr uint128(int128 v);  // NOLINT(runtime/explicit)
                explicit uint128(float v);
                explicit uint128(double v);
                explicit uint128(long double v);

                // Assignment operators from arithmetic types
                uint128 &operator=(int v);
                uint128 &operator=(unsigned int v);
                uint128 &operator=(long v);                // NOLINT(runtime/int)
                uint128 &operator=(unsigned long v);       // NOLINT(runtime/int)
                uint128 &operator=(long long v);           // NOLINT(runtime/int)
                uint128 &operator=(unsigned long long v);  // NOLINT(runtime/int)
#ifdef STL_HAVE_INTRINSIC_INT128
                uint128 &operator=(__int128 v);
                uint128 &operator=(unsigned __int128 v);
#endif  // STL_HAVE_INTRINSIC_INT128
                uint128 &operator=(int128 v);

                // Conversion operators to other arithmetic types
                constexpr explicit operator bool() const;
                constexpr explicit operator char() const;
                constexpr explicit operator signed char() const;
                constexpr explicit operator unsigned char() const;
                constexpr explicit operator char16_t() const;
                constexpr explicit operator char32_t() const;
                constexpr explicit operator short() const;  // NOLINT(runtime/int)
                // NOLINTNEXTLINE(runtime/int)
                constexpr explicit operator unsigned short() const;
                constexpr explicit operator int() const;
                constexpr explicit operator unsigned int() const;
                constexpr explicit operator long() const;  // NOLINT(runtime/int)
                // NOLINTNEXTLINE(runtime/int)
                constexpr explicit operator unsigned long() const;
                // NOLINTNEXTLINE(runtime/int)
                constexpr explicit operator long long() const;
                // NOLINTNEXTLINE(runtime/int)
                constexpr explicit operator unsigned long long() const;
#ifdef STL_HAVE_INTRINSIC_INT128
                constexpr explicit operator __int128() const;
                constexpr explicit operator unsigned __int128() const;
#endif  // STL_HAVE_INTRINSIC_INT128
                explicit operator float() const;
                explicit operator double() const;
                explicit operator long double() const;

                // Trivial copy constructor, assignment operator and destructor.

                // Arithmetic operators.
                uint128 &operator+=(uint128 other);
                uint128 &operator-=(uint128 other);
                uint128 &operator*=(uint128 other);
                // Long division/modulo for uint128.
                uint128 &operator/=(uint128 other);
                uint128 &operator%=(uint128 other);
                uint128 operator++(int);
                uint128 operator--(int);
                uint128 &operator<<=(int);
                uint128 &operator>>=(int);
                uint128 &operator&=(uint128 other);
                uint128 &operator|=(uint128 other);
                uint128 &operator^=(uint128 other);
                uint128 &operator++();
                uint128 &operator--();

                // Uint128Low64()
                //
                // Returns the lower 64-bit value of a `uint128` value.
                friend constexpr uint64_t Uint128Low64(uint128 v);

                // Uint128High64()
                //
                // Returns the higher 64-bit value of a `uint128` value.
                friend constexpr uint64_t Uint128High64(uint128 v);

                // MakeUInt128()
                //
                // Constructs a `uint128` numeric value from two 64-bit unsigned integers.
                // Note that this factory function is the only way to construct a `uint128`
                // from integer values greater than 2^64.
                //
                // Example:
                //
                //   stl::uint128 big = stl::MakeUint128(1, 0);
                friend constexpr uint128 MakeUint128(uint64_t high, uint64_t low);

                // Uint128Max()
                //
                // Returns the highest value for a 128-bit unsigned integer.
                friend constexpr uint128 Uint128Max();

                // Support for stl::Hash.
                template<typename H>
                friend H HashValue(H h, uint128 v) {
                    return H::combine(std::move(h), Uint128High64(v), Uint128Low64(v));
                }

            private:
                constexpr uint128(uint64_t high, uint64_t low);

#if defined(STL_IS_LITTLE_ENDIAN)
                uint64_t lo_;
                uint64_t hi_;
#elif defined(STL_IS_BIG_ENDIAN)
                uint64_t hi_;
                uint64_t lo_;
#else  // byte order
#error "Unsupported byte order: must be little-endian or big-endian."
#endif  // byte order
            };

// allow uint128 to be logged
            std::ostream &operator<<(std::ostream &os, uint128 v);

            constexpr uint128 Uint128Max() {
                return uint128((std::numeric_limits<uint64_t>::max)(),
                               (std::numeric_limits<uint64_t>::max)());
            }
        } // namespace __INTERNAL

// Spcialized numeric_limits for uint128
_LIB_END_NAMESPACE_STL

namespace std {
    template<>
    class numeric_limits<stl::__INTERNAL::uint128> {
    public:
        static constexpr bool is_specialized = true;
        static constexpr bool is_signed = false;
        static constexpr bool is_integer = true;
        static constexpr bool is_exact = true;
        static constexpr bool has_infinity = false;
        static constexpr bool has_quiet_NaN = false;
        static constexpr bool has_signaling_NaN = false;
        static constexpr float_denorm_style has_denorm = denorm_absent;
        static constexpr bool has_denorm_loss = false;
        static constexpr float_round_style round_style = round_toward_zero;
        static constexpr bool is_iec559 = false;
        static constexpr bool is_bounded = true;
        static constexpr bool is_modulo = true;
        static constexpr int digits = 128;
        static constexpr int digits10 = 38;
        static constexpr int max_digits10 = 0;
        static constexpr int radix = 2;
        static constexpr int min_exponent = 0;
        static constexpr int min_exponent10 = 0;
        static constexpr int max_exponent = 0;
        static constexpr int max_exponent10 = 0;
#ifdef STL_HAVE_INTRINSIC_INT128
        static constexpr bool traps = numeric_limits<unsigned __int128>::traps;
#else  // STL_HAVE_INTRINSIC_INT128
        static constexpr bool traps = numeric_limits<uint64_t>::traps;
#endif  // STL_HAVE_INTRINSIC_INT128
        static constexpr bool tinyness_before = false;

        static constexpr stl::__INTERNAL::uint128 (min)() { return 0; }
        static constexpr stl::__INTERNAL::uint128 lowest() { return 0; }
        static constexpr stl::__INTERNAL::uint128 (max)() { return stl::__INTERNAL::Uint128Max(); }
        static constexpr stl::__INTERNAL::uint128 epsilon() { return 0; }
        static constexpr stl::__INTERNAL::uint128 round_error() { return 0; }
        static constexpr stl::__INTERNAL::uint128 infinity() { return 0; }
        static constexpr stl::__INTERNAL::uint128 quiet_NaN() { return 0; }
        static constexpr stl::__INTERNAL::uint128 signaling_NaN() { return 0; }
        static constexpr stl::__INTERNAL::uint128 denorm_min() { return 0; }
    };
}  // namespace std


_LIB_BEGIN_NAMESPACE_STL
// int128 function
        namespace __INTERNAL {

// int128
//
// A signed 128-bit integer type. The API is meant to mimic an intrinsic
// integral type as closely as is practical, including exhibiting undefined
// behavior in analogous cases (e.g. division by zero).
//
// An `int128` supports the following:
//
//   * Implicit construction from integral types
//   * Explicit conversion to integral types
//
// However, an `int128` differs from intrinsic integral types in the following
// ways:
//
//   * It is not implicitly convertible to other integral types.
//   * Requires explicit construction from and conversion to floating point
//     types.

// Additionally, if your compiler supports `__int128`, `int128` is
// interoperable with that type. (Abseil checks for this compatibility through
// the `STL_HAVE_INTRINSIC_INT128` macro.)
//
// The design goal for `int128` is that it will be compatible with a future
// `int128_t`, if that type becomes a part of the standard.
//
// Example:
//
//     float y = stl::int128(17);  // Error. int128 cannot be implicitly
//                                  // converted to float.
//
//     stl::int128 v;
//     int64_t i = v;                        // Error
//     int64_t i = static_cast<int64_t>(v);  // OK
//
            class int128 {
            public:
                int128() = default;

                // Constructors from arithmetic types
                constexpr int128(int v);                 // NOLINT(runtime/explicit)
                constexpr int128(unsigned int v);        // NOLINT(runtime/explicit)
                constexpr int128(long v);                // NOLINT(runtime/int)
                constexpr int128(unsigned long v);       // NOLINT(runtime/int)
                constexpr int128(long long v);           // NOLINT(runtime/int)
                constexpr int128(unsigned long long v);  // NOLINT(runtime/int)
#ifdef STL_HAVE_INTRINSIC_INT128
                constexpr int128(__int128 v);  // NOLINT(runtime/explicit)
                constexpr explicit int128(unsigned __int128 v);
#endif  // STL_HAVE_INTRINSIC_INT128
                constexpr explicit int128(uint128 v);
                explicit int128(float v);
                explicit int128(double v);
                explicit int128(long double v);

                // Assignment operators from arithmetic types
                int128 &operator=(int v);
                int128 &operator=(unsigned int v);
                int128 &operator=(long v);                // NOLINT(runtime/int)
                int128 &operator=(unsigned long v);       // NOLINT(runtime/int)
                int128 &operator=(long long v);           // NOLINT(runtime/int)
                int128 &operator=(unsigned long long v);  // NOLINT(runtime/int)
#ifdef STL_HAVE_INTRINSIC_INT128
                int128 &operator=(__int128 v);
#endif  // STL_HAVE_INTRINSIC_INT128

                // Conversion operators to other arithmetic types
                constexpr explicit operator bool() const;
                constexpr explicit operator char() const;
                constexpr explicit operator signed char() const;
                constexpr explicit operator unsigned char() const;
                constexpr explicit operator char16_t() const;
                constexpr explicit operator char32_t() const;
                constexpr explicit operator short() const;  // NOLINT(runtime/int)
                // NOLINTNEXTLINE(runtime/int)
                constexpr explicit operator unsigned short() const;
                constexpr explicit operator int() const;
                constexpr explicit operator unsigned int() const;
                constexpr explicit operator long() const;  // NOLINT(runtime/int)
                // NOLINTNEXTLINE(runtime/int)
                constexpr explicit operator unsigned long() const;
                // NOLINTNEXTLINE(runtime/int)
                constexpr explicit operator long long() const;
                // NOLINTNEXTLINE(runtime/int)
                constexpr explicit operator unsigned long long() const;
#ifdef STL_HAVE_INTRINSIC_INT128
                constexpr explicit operator __int128() const;
                constexpr explicit operator unsigned __int128() const;
#endif  // STL_HAVE_INTRINSIC_INT128
                explicit operator float() const;
                explicit operator double() const;
                explicit operator long double() const;

                // Trivial copy constructor, assignment operator and destructor.

                // Arithmetic operators
                int128 &operator+=(int128 other);
                int128 &operator-=(int128 other);
                int128 &operator*=(int128 other);
                int128 &operator/=(int128 other);
                int128 &operator%=(int128 other);
                int128 operator++(int);  // postfix increment: i++
                int128 operator--(int);  // postfix decrement: i--
                int128 &operator++();    // prefix increment:  ++i
                int128 &operator--();    // prefix decrement:  --i
                int128 &operator&=(int128 other);
                int128 &operator|=(int128 other);
                int128 &operator^=(int128 other);
                int128 &operator<<=(int amount);
                int128 &operator>>=(int amount);

                // Int128Low64()
                //
                // Returns the lower 64-bit value of a `int128` value.
                friend constexpr uint64_t Int128Low64(int128 v);

                // Int128High64()
                //
                // Returns the higher 64-bit value of a `int128` value.
                friend constexpr int64_t Int128High64(int128 v);

                // MakeInt128()
                //
                // Constructs a `int128` numeric value from two 64-bit integers. Note that
                // signedness is conveyed in the upper `high` value.
                //
                //   (stl::int128(1) << 64) * high + low
                //
                // Note that this factory function is the only way to construct a `int128`
                // from integer values greater than 2^64 or less than -2^64.
                //
                // Example:
                //
                //   stl::int128 big = stl::MakeInt128(1, 0);
                //   stl::int128 big_n = stl::MakeInt128(-1, 0);
                friend constexpr int128 MakeInt128(int64_t high, uint64_t low);

                // Int128Max()
                //
                // Returns the maximum value for a 128-bit signed integer.
                friend constexpr int128 Int128Max();

                // Int128Min()
                //
                // Returns the minimum value for a 128-bit signed integer.
                friend constexpr int128 Int128Min();
            private:
                constexpr int128(int64_t high, uint64_t low);

#if defined(STL_HAVE_INTRINSIC_INT128)
                __int128 v_;
#else  // STL_HAVE_INTRINSIC_INT128
#if defined(STL_IS_LITTLE_ENDIAN)
                uint64_t lo_;
                int64_t hi_;
#elif defined(STL_IS_BIG_ENDIAN)
                int64_t hi_;
                uint64_t lo_;
#else  // byte order
#error "Unsupported byte order: must be little-endian or big-endian."
#endif  // byte order
#endif  // STL_HAVE_INTRINSIC_INT128
            };

            std::ostream &operator<<(std::ostream &os, int128 v);

            constexpr int128 Int128Max() {
                return int128((std::numeric_limits<int64_t>::max)(),
                              (std::numeric_limits<uint64_t>::max)());
            }

            constexpr int128 Int128Min() {
                return int128((std::numeric_limits<int64_t>::min)(), 0);
            }
        } // namespace __INTERNAL
_LIB_END_NAMESPACE_STL

// Specialized numeric_limits for int128.
namespace std {
    template<>
    class numeric_limits<stl::__INTERNAL::int128> {
    public:
        static constexpr bool is_specialized = true;
        static constexpr bool is_signed = true;
        static constexpr bool is_integer = true;
        static constexpr bool is_exact = true;
        static constexpr bool has_infinity = false;
        static constexpr bool has_quiet_NaN = false;
        static constexpr bool has_signaling_NaN = false;
        static constexpr float_denorm_style has_denorm = denorm_absent;
        static constexpr bool has_denorm_loss = false;
        static constexpr float_round_style round_style = round_toward_zero;
        static constexpr bool is_iec559 = false;
        static constexpr bool is_bounded = true;
        static constexpr bool is_modulo = false;
        static constexpr int digits = 127;
        static constexpr int digits10 = 38;
        static constexpr int max_digits10 = 0;
        static constexpr int radix = 2;
        static constexpr int min_exponent = 0;
        static constexpr int min_exponent10 = 0;
        static constexpr int max_exponent = 0;
        static constexpr int max_exponent10 = 0;
#ifdef STL_HAVE_INTRINSIC_INT128
        static constexpr bool traps = numeric_limits<__int128>::traps;
#else  // STL_HAVE_INTRINSIC_INT128
        static constexpr bool traps = numeric_limits<uint64_t>::traps;
#endif  // STL_HAVE_INTRINSIC_INT128
        static constexpr bool tinyness_before = false;
        static constexpr stl::__INTERNAL::int128 (min)() { return stl::__INTERNAL::Int128Min(); }
        static constexpr stl::__INTERNAL::int128 lowest() { return stl::__INTERNAL::Int128Min(); }
        static constexpr stl::__INTERNAL::int128 (max)() { return stl::__INTERNAL::Int128Max(); }
        static constexpr stl::__INTERNAL::int128 epsilon() { return 0; }
        static constexpr stl::__INTERNAL::int128 round_error() { return 0; }
        static constexpr stl::__INTERNAL::int128 infinity() { return 0; }
        static constexpr stl::__INTERNAL::int128 quiet_NaN() { return 0; }
        static constexpr stl::__INTERNAL::int128 signaling_NaN() { return 0; }
        static constexpr stl::__INTERNAL::int128 denorm_min() { return 0; }
    };
}  // namespace std

_LIB_BEGIN_NAMESPACE_STL
        namespace __INTERNAL {

            constexpr uint128 MakeUint128(uint64_t high, uint64_t low) {
                return uint128(high, low);
            }

// Assignment from integer types.

            inline uint128 &uint128::operator=(int v) { return *this = uint128(v); }

            inline uint128 &uint128::operator=(unsigned int v) {
                return *this = uint128(v);
            }

            inline uint128 &uint128::operator=(long v) {  // NOLINT(runtime/int)
                return *this = uint128(v);
            }

// NOLINTNEXTLINE(runtime/int)
            inline uint128 &uint128::operator=(unsigned long v) {
                return *this = uint128(v);
            }

// NOLINTNEXTLINE(runtime/int)
            inline uint128 &uint128::operator=(long long v) {
                return *this = uint128(v);
            }

// NOLINTNEXTLINE(runtime/int)
            inline uint128 &uint128::operator=(unsigned long long v) {
                return *this = uint128(v);
            }

#ifdef STL_HAVE_INTRINSIC_INT128
            inline uint128& uint128::operator=(__int128 v) {
          return *this = uint128(v);
        }

        inline uint128& uint128::operator=(unsigned __int128 v) {
          return *this = uint128(v);
        }
#endif  // STL_HAVE_INTRINSIC_INT128

            inline uint128 &uint128::operator=(int128 v) {
                return *this = uint128(v);
            }

// Arithmetic operators.

            uint128 operator<<(uint128 lhs, int amount);
            uint128 operator>>(uint128 lhs, int amount);
            uint128 operator+(uint128 lhs, uint128 rhs);
            uint128 operator-(uint128 lhs, uint128 rhs);
            uint128 operator*(uint128 lhs, uint128 rhs);
            uint128 operator/(uint128 lhs, uint128 rhs);
            uint128 operator%(uint128 lhs, uint128 rhs);

            inline uint128 &uint128::operator<<=(int amount) {
                *this = *this << amount;
                return *this;
            }

            inline uint128 &uint128::operator>>=(int amount) {
                *this = *this >> amount;
                return *this;
            }

            inline uint128 &uint128::operator+=(uint128 other) {
                *this = *this + other;
                return *this;
            }

            inline uint128 &uint128::operator-=(uint128 other) {
                *this = *this - other;
                return *this;
            }

            inline uint128 &uint128::operator*=(uint128 other) {
                *this = *this * other;
                return *this;
            }

            inline uint128 &uint128::operator/=(uint128 other) {
                *this = *this / other;
                return *this;
            }

            inline uint128 &uint128::operator%=(uint128 other) {
                *this = *this % other;
                return *this;
            }

            constexpr uint64_t Uint128Low64(uint128 v) { return v.lo_; }

            constexpr uint64_t Uint128High64(uint128 v) { return v.hi_; }

// Constructors from integer types.

#if defined(STL_IS_LITTLE_ENDIAN)

            constexpr uint128::uint128(uint64_t high, uint64_t low)
                    : lo_{low}, hi_{high} {}

            constexpr uint128::uint128(int v)
                    : lo_{static_cast<uint64_t>(v)},
                      hi_{v < 0 ? (std::numeric_limits<uint64_t>::max)() : 0} {}
            constexpr uint128::uint128(long v)  // NOLINT(runtime/int)
                    : lo_{static_cast<uint64_t>(v)},
                      hi_{v < 0 ? (std::numeric_limits<uint64_t>::max)() : 0} {}
            constexpr uint128::uint128(long long v)  // NOLINT(runtime/int)
                    : lo_{static_cast<uint64_t>(v)},
                      hi_{v < 0 ? (std::numeric_limits<uint64_t>::max)() : 0} {}

            constexpr uint128::uint128(unsigned int v) : lo_{v}, hi_{0} {}
// NOLINTNEXTLINE(runtime/int)
            constexpr uint128::uint128(unsigned long v) : lo_{v}, hi_{0} {}
// NOLINTNEXTLINE(runtime/int)
            constexpr uint128::uint128(unsigned long long v) : lo_{v}, hi_{0} {}

#ifdef STL_HAVE_INTRINSIC_INT128
            constexpr uint128::uint128(__int128 v)
                : lo_{static_cast<uint64_t>(v & ~uint64_t{0})},
                  hi_{static_cast<uint64_t>(static_cast<unsigned __int128>(v) >> 64)} {}
            constexpr uint128::uint128(unsigned __int128 v)
                : lo_{static_cast<uint64_t>(v & ~uint64_t{0})},
                  hi_{static_cast<uint64_t>(v >> 64)} {}
#endif  // STL_HAVE_INTRINSIC_INT128

            constexpr uint128::uint128(int128 v)
                    : lo_{Int128Low64(v)}, hi_{static_cast<uint64_t>(Int128High64(v))} {}

#elif defined(STL_IS_BIG_ENDIAN)

            constexpr uint128::uint128(uint64_t high, uint64_t low)
            : hi_{high}, lo_{low} {}

        constexpr uint128::uint128(int v)
            : hi_{v < 0 ? (std::numeric_limits<uint64_t>::max)() : 0},
              lo_{static_cast<uint64_t>(v)} {}
        constexpr uint128::uint128(long v)  // NOLINT(runtime/int)
            : hi_{v < 0 ? (std::numeric_limits<uint64_t>::max)() : 0},
              lo_{static_cast<uint64_t>(v)} {}
        constexpr uint128::uint128(long long v)  // NOLINT(runtime/int)
            : hi_{v < 0 ? (std::numeric_limits<uint64_t>::max)() : 0},
              lo_{static_cast<uint64_t>(v)} {}

        constexpr uint128::uint128(unsigned int v) : hi_{0}, lo_{v} {}
        // NOLINTNEXTLINE(runtime/int)
        constexpr uint128::uint128(unsigned long v) : hi_{0}, lo_{v} {}
        // NOLINTNEXTLINE(runtime/int)
        constexpr uint128::uint128(unsigned long long v) : hi_{0}, lo_{v} {}

#ifdef STL_HAVE_INTRINSIC_INT128
        constexpr uint128::uint128(__int128 v)
            : hi_{static_cast<uint64_t>(static_cast<unsigned __int128>(v) >> 64)},
              lo_{static_cast<uint64_t>(v & ~uint64_t{0})} {}
        constexpr uint128::uint128(unsigned __int128 v)
            : hi_{static_cast<uint64_t>(v >> 64)},
              lo_{static_cast<uint64_t>(v & ~uint64_t{0})} {}
#endif  // STL_HAVE_INTRINSIC_INT128

        constexpr uint128::uint128(int128 v)
            : hi_{static_cast<uint64_t>(Int128High64(v))}, lo_{Int128Low64(v)} {}
#endif  // byte order

// Conversion operators to integer types.

            constexpr uint128::operator bool() const { return lo_ || hi_; }

            constexpr uint128::operator char() const { return static_cast<char>(lo_); }

            constexpr uint128::operator signed char() const {
                return static_cast<signed char>(lo_);
            }

            constexpr uint128::operator unsigned char() const {
                return static_cast<unsigned char>(lo_);
            }

            constexpr uint128::operator char16_t() const {
                return static_cast<char16_t>(lo_);
            }

            constexpr uint128::operator char32_t() const {
                return static_cast<char32_t>(lo_);
            }

// NOLINTNEXTLINE(runtime/int)
            constexpr uint128::operator short() const { return static_cast<short>(lo_); }

            constexpr uint128::operator unsigned short() const {  // NOLINT(runtime/int)
                return static_cast<unsigned short>(lo_);            // NOLINT(runtime/int)
            }

            constexpr uint128::operator int() const { return static_cast<int>(lo_); }

            constexpr uint128::operator unsigned int() const {
                return static_cast<unsigned int>(lo_);
            }

// NOLINTNEXTLINE(runtime/int)
            constexpr uint128::operator long() const { return static_cast<long>(lo_); }

            constexpr uint128::operator unsigned long() const {  // NOLINT(runtime/int)
                return static_cast<unsigned long>(lo_);            // NOLINT(runtime/int)
            }

            constexpr uint128::operator long long() const {  // NOLINT(runtime/int)
                return static_cast<long long>(lo_);            // NOLINT(runtime/int)
            }

            constexpr uint128::operator unsigned long long() const {  // NOLINT(runtime/int)
                return static_cast<unsigned long long>(lo_);            // NOLINT(runtime/int)
            }

#ifdef STL_HAVE_INTRINSIC_INT128
            constexpr uint128::operator __int128() const {
          return (static_cast<__int128>(hi_) << 64) + lo_;
        }

        constexpr uint128::operator unsigned __int128() const {
          return (static_cast<unsigned __int128>(hi_) << 64) + lo_;
        }
#endif  // STL_HAVE_INTRINSIC_INT128

// Conversion operators to floating point types.

            inline uint128::operator float() const {
                return static_cast<float>(lo_) + ::std::ldexp(static_cast<float>(hi_), 64);
            }

            inline uint128::operator double() const {
                return static_cast<double>(lo_) + ::std::ldexp(static_cast<double>(hi_), 64);
            }

            inline uint128::operator long double() const {
                return static_cast<long double>(lo_) +
                       ::std::ldexp(static_cast<long double>(hi_), 64);
            }

// Comparison operators.

            inline bool operator==(uint128 lhs, uint128 rhs) {
                return (Uint128Low64(lhs) == Uint128Low64(rhs) &&
                        Uint128High64(lhs) == Uint128High64(rhs));
            }

            inline bool operator!=(uint128 lhs, uint128 rhs) {
                return !(lhs == rhs);
            }

            inline bool operator<(uint128 lhs, uint128 rhs) {
#ifdef STL_HAVE_INTRINSIC_INT128
                return static_cast<unsigned __int128>(lhs) <
                 static_cast<unsigned __int128>(rhs);
#else
                return (Uint128High64(lhs) == Uint128High64(rhs))
                       ? (Uint128Low64(lhs) < Uint128Low64(rhs))
                       : (Uint128High64(lhs) < Uint128High64(rhs));
#endif
            }

            inline bool operator>(uint128 lhs, uint128 rhs) { return rhs < lhs; }

            inline bool operator<=(uint128 lhs, uint128 rhs) { return !(rhs < lhs); }

            inline bool operator>=(uint128 lhs, uint128 rhs) { return !(lhs < rhs); }

// Unary operators.

            inline uint128 operator-(uint128 val) {
                uint64_t hi = ~Uint128High64(val);
                uint64_t lo = ~Uint128Low64(val) + 1;
                if (lo == 0) ++hi;  // carry
                return MakeUint128(hi, lo);
            }

            inline bool operator!(uint128 val) {
                return !Uint128High64(val) && !Uint128Low64(val);
            }

// Logical operators.

            inline uint128 operator~(uint128 val) {
                return MakeUint128(~Uint128High64(val), ~Uint128Low64(val));
            }

            inline uint128 operator|(uint128 lhs, uint128 rhs) {
                return MakeUint128(Uint128High64(lhs) | Uint128High64(rhs),
                                   Uint128Low64(lhs) | Uint128Low64(rhs));
            }

            inline uint128 operator&(uint128 lhs, uint128 rhs) {
                return MakeUint128(Uint128High64(lhs) & Uint128High64(rhs),
                                   Uint128Low64(lhs) & Uint128Low64(rhs));
            }

            inline uint128 operator^(uint128 lhs, uint128 rhs) {
                return MakeUint128(Uint128High64(lhs) ^ Uint128High64(rhs),
                                   Uint128Low64(lhs) ^ Uint128Low64(rhs));
            }

            inline uint128 &uint128::operator|=(uint128 other) {
                hi_ |= other.hi_;
                lo_ |= other.lo_;
                return *this;
            }

            inline uint128 &uint128::operator&=(uint128 other) {
                hi_ &= other.hi_;
                lo_ &= other.lo_;
                return *this;
            }

            inline uint128 &uint128::operator^=(uint128 other) {
                hi_ ^= other.hi_;
                lo_ ^= other.lo_;
                return *this;
            }

// Arithmetic operators.

            inline uint128 operator<<(uint128 lhs, int amount) {
#ifdef STL_HAVE_INTRINSIC_INT128
                return static_cast<unsigned __int128>(lhs) << amount;
#else
                // uint64_t shifts of >= 64 are undefined, so we will need some
                // special-casing.
                if (amount < 64) {
                    if (amount != 0) {
                        return MakeUint128(
                                (Uint128High64(lhs) << amount) | (Uint128Low64(lhs) >> (64 - amount)),
                                Uint128Low64(lhs) << amount);
                    }
                    return lhs;
                }
                return MakeUint128(Uint128Low64(lhs) << (amount - 64), 0);
#endif
            }

            inline uint128 operator>>(uint128 lhs, int amount) {
#ifdef STL_HAVE_INTRINSIC_INT128
                return static_cast<unsigned __int128>(lhs) >> amount;
#else
                // uint64_t shifts of >= 64 are undefined, so we will need some
                // special-casing.
                if (amount < 64) {
                    if (amount != 0) {
                        return MakeUint128(Uint128High64(lhs) >> amount,
                                           (Uint128Low64(lhs) >> amount) |
                                           (Uint128High64(lhs) << (64 - amount)));
                    }
                    return lhs;
                }
                return MakeUint128(0, Uint128High64(lhs) >> (amount - 64));
#endif
            }

            inline uint128 operator+(uint128 lhs, uint128 rhs) {
                uint128 result = MakeUint128(Uint128High64(lhs) + Uint128High64(rhs),
                                             Uint128Low64(lhs) + Uint128Low64(rhs));
                if (Uint128Low64(result) < Uint128Low64(lhs)) {  // check for carry
                    return MakeUint128(Uint128High64(result) + 1, Uint128Low64(result));
                }
                return result;
            }

            inline uint128 operator-(uint128 lhs, uint128 rhs) {
                uint128 result = MakeUint128(Uint128High64(lhs) - Uint128High64(rhs),
                                             Uint128Low64(lhs) - Uint128Low64(rhs));
                if (Uint128Low64(lhs) < Uint128Low64(rhs)) {  // check for carry
                    return MakeUint128(Uint128High64(result) - 1, Uint128Low64(result));
                }
                return result;
            }

            inline uint128 operator*(uint128 lhs, uint128 rhs) {
#if defined(STL_HAVE_INTRINSIC_INT128)
                // TODO(strel) Remove once alignment issues are resolved and unsigned __int128
          // can be used for uint128 storage.
          return static_cast<unsigned __int128>(lhs) *
                 static_cast<unsigned __int128>(rhs);
#elif defined(_MSC_VER) && defined(_M_X64)
                uint64_t carry;
          uint64_t low = _umul128(Uint128Low64(lhs), Uint128Low64(rhs), &carry);
          return MakeUint128(Uint128Low64(lhs) * Uint128High64(rhs) +
                                 Uint128High64(lhs) * Uint128Low64(rhs) + carry,
                             low);
#else   // STL_HAVE_INTRINSIC128
                uint64_t a32 = Uint128Low64(lhs) >> 32;
                uint64_t a00 = Uint128Low64(lhs) & 0xffffffff;
                uint64_t b32 = Uint128Low64(rhs) >> 32;
                uint64_t b00 = Uint128Low64(rhs) & 0xffffffff;
                uint128 result =
                        MakeUint128(Uint128High64(lhs) * Uint128Low64(rhs) +
                                    Uint128Low64(lhs) * Uint128High64(rhs) + a32 * b32,
                                    a00 * b00);
                result += uint128(a32 * b00) << 32;
                result += uint128(a00 * b32) << 32;
                return result;
#endif  // STL_HAVE_INTRINSIC128
            }

// Increment/decrement operators.

            inline uint128 uint128::operator++(int) {
                uint128 tmp(*this);
                *this += 1;
                return tmp;
            }

            inline uint128 uint128::operator--(int) {
                uint128 tmp(*this);
                *this -= 1;
                return tmp;
            }

            inline uint128 &uint128::operator++() {
                *this += 1;
                return *this;
            }

            inline uint128 &uint128::operator--() {
                *this -= 1;
                return *this;
            }

            constexpr int128 MakeInt128(int64_t high, uint64_t low) {
                return int128(high, low);
            }

// Assignment from integer types.
            inline int128 &int128::operator=(int v) {
                return *this = int128(v);
            }

            inline int128 &int128::operator=(unsigned int v) {
                return *this = int128(v);
            }

            inline int128 &int128::operator=(long v) {  // NOLINT(runtime/int)
                return *this = int128(v);
            }

// NOLINTNEXTLINE(runtime/int)
            inline int128 &int128::operator=(unsigned long v) {
                return *this = int128(v);
            }

// NOLINTNEXTLINE(runtime/int)
            inline int128 &int128::operator=(long long v) {
                return *this = int128(v);
            }

// NOLINTNEXTLINE(runtime/int)
            inline int128 &int128::operator=(unsigned long long v) {
                return *this = int128(v);
            }

// Arithmetic operators.

            int128 operator+(int128 lhs, int128 rhs);
            int128 operator-(int128 lhs, int128 rhs);
            int128 operator*(int128 lhs, int128 rhs);
            int128 operator/(int128 lhs, int128 rhs);
            int128 operator%(int128 lhs, int128 rhs);
            int128 operator|(int128 lhs, int128 rhs);
            int128 operator&(int128 lhs, int128 rhs);
            int128 operator^(int128 lhs, int128 rhs);
            int128 operator<<(int128 lhs, int amount);
            int128 operator>>(int128 lhs, int amount);

            inline int128 &int128::operator+=(int128 other) {
                *this = *this + other;
                return *this;
            }
            inline int128 &int128::operator-=(int128 other) {
                *this = *this - other;
                return *this;
            }
            inline int128 &int128::operator*=(int128 other) {
                *this = *this * other;
                return *this;
            }
            inline int128 &int128::operator/=(int128 other) {
                *this = *this / other;
                return *this;
            }
            inline int128 &int128::operator%=(int128 other) {
                *this = *this % other;
                return *this;
            }
            inline int128 &int128::operator|=(int128 other) {
                *this = *this | other;
                return *this;
            }
            inline int128 &int128::operator&=(int128 other) {
                *this = *this & other;
                return *this;
            }
            inline int128 &int128::operator^=(int128 other) {
                *this = *this ^ other;
                return *this;
            }
            inline int128 &int128::operator<<=(int amount) {
                *this = *this << amount;
                return *this;
            }
            inline int128 &int128::operator>>=(int amount) {
                *this = *this >> amount;
                return *this;
            }
            namespace int128_internal {
                constexpr int64_t BitCastToSigned(uint64_t v) {
                    return v & (uint64_t{1} << 63) ? ~static_cast<int64_t>(~v)
                                                   : static_cast<int64_t>(v);
                }
            }  // namespace int128_internal
        }


        namespace __INTERNAL {
            namespace int128_internal {

// Casts from unsigned to signed while preserving the underlying binary
// representation.
                constexpr __int128 BitCastToSigned(unsigned __int128 v) {
                    // Casting an unsigned integer to a signed integer of the same
                    // width is implementation defined behavior if the source value would not fit
                    // in the destination type. We step around it with a roundtrip bitwise not
                    // operation to make sure this function remains constexpr. Clang and GCC
                    // optimize this to a no-op on x86-64.
                    return v & (static_cast<unsigned __int128>(1) << 127)
                           ? ~static_cast<__int128>(~v)
                           : static_cast<__int128>(v);
                }

            }  // namespace int128_internal
            inline int128 &int128::operator=(__int128 v) {
                v_ = v;
                return *this;
            }
            constexpr uint64_t Int128Low64(int128 v) {
                return static_cast<uint64_t>(v.v_ & ~uint64_t{0});
            }

            constexpr int64_t Int128High64(int128 v) {
                // Initially cast to unsigned to prevent a right shift on a negative value.
                return int128_internal::BitCastToSigned(
                        static_cast<uint64_t>(static_cast<unsigned __int128>(v.v_) >> 64));
            }

            constexpr int128::int128(int64_t high, uint64_t low)
// Initially cast to unsigned to prevent a left shift that overflows.
                    : v_(int128_internal::BitCastToSigned(static_cast<unsigned __int128>(high)
                                                                  << 64) |
                         low) {}


            constexpr int128::int128(int v) : v_{v} {}

            constexpr int128::int128(long v) : v_{v} {}       // NOLINT(runtime/int)

            constexpr int128::int128(long long v) : v_{v} {}  // NOLINT(runtime/int)

            constexpr int128::int128(__int128 v) : v_{v} {}

            constexpr int128::int128(unsigned int v) : v_{v} {}

            constexpr int128::int128(unsigned long v) : v_{v} {}  // NOLINT(runtime/int)

// NOLINTNEXTLINE(runtime/int)
            constexpr int128::int128(unsigned long long v) : v_{v} {}

            constexpr int128::int128(unsigned __int128 v) : v_{static_cast<__int128>(v)} {}

            inline int128::int128(float v) {
                v_ = static_cast<__int128>(v);
            }

            inline int128::int128(double v) {
                v_ = static_cast<__int128>(v);
            }

            inline int128::int128(long double v) {
                v_ = static_cast<__int128>(v);
            }

            constexpr int128::int128(uint128 v) : v_{static_cast<__int128>(v)} {}

            constexpr int128::operator bool() const { return static_cast<bool>(v_); }

            constexpr int128::operator char() const { return static_cast<char>(v_); }

            constexpr int128::operator signed char() const {
                return static_cast<signed char>(v_);
            }

            constexpr int128::operator unsigned char() const {
                return static_cast<unsigned char>(v_);
            }

            constexpr int128::operator char16_t() const {
                return static_cast<char16_t>(v_);
            }

            constexpr int128::operator char32_t() const {
                return static_cast<char32_t>(v_);
            }

            constexpr int128::operator short() const {  // NOLINT(runtime/int)
                return static_cast<short>(v_);            // NOLINT(runtime/int)
            }

            constexpr int128::operator unsigned short() const {  // NOLINT(runtime/int)
                return static_cast<unsigned short>(v_);            // NOLINT(runtime/int)
            }

            constexpr int128::operator int() const {
                return static_cast<int>(v_);
            }

            constexpr int128::operator unsigned int() const {
                return static_cast<unsigned int>(v_);
            }

            constexpr int128::operator long() const {  // NOLINT(runtime/int)
                return static_cast<long>(v_);            // NOLINT(runtime/int)
            }

            constexpr int128::operator unsigned long() const {  // NOLINT(runtime/int)
                return static_cast<unsigned long>(v_);            // NOLINT(runtime/int)
            }

            constexpr int128::operator long long() const {  // NOLINT(runtime/int)
                return static_cast<long long>(v_);            // NOLINT(runtime/int)
            }

            constexpr int128::operator unsigned long long() const {  // NOLINT(runtime/int)
                return static_cast<unsigned long long>(v_);            // NOLINT(runtime/int)
            }

            constexpr int128::operator __int128() const { return v_; }

            constexpr int128::operator unsigned __int128() const {
                return static_cast<unsigned __int128>(v_);
            }

// Clang on PowerPC sometimes produces incorrect __int128 to floating point
// conversions. In that case, we do the conversion with a similar implementation
// to the conversion operators in int128_no_intrinsic.inc.
#if defined(__clang__) && !defined(__ppc64__)
            inline int128::operator float() const { return static_cast<float>(v_); }
            inline int128::operator double () const { return static_cast<double>(v_); }
            inline int128::operator long double() const {
      return static_cast<long double>(v_);
    }

#else  // Clang on PowerPC
// Forward declaration for conversion operators to floating point types.
            int128 operator-(int128 v);
            bool operator!=(int128 lhs, int128 rhs);

            inline int128::operator float() const {
                // We must convert the absolute value and then negate as needed, because
                // floating point types are typically sign-magnitude. Otherwise, the
                // difference between the high and low 64 bits when interpreted as two's
                // complement overwhelms the precision of the mantissa.
                //
                // Also check to make sure we don't negate Int128Min()
                return v_ < 0 && *this != Int128Min()
                       ? -static_cast<float>(-*this)
                       : static_cast<float>(Int128Low64(*this)) +
                         std::ldexp(static_cast<float>(Int128High64(*this)), 64);
            }

            inline int128::operator double() const {
                // See comment in int128::operator float() above.
                return v_ < 0 && *this != Int128Min()
                       ? -static_cast<double>(-*this)
                       : static_cast<double>(Int128Low64(*this)) +
                         std::ldexp(static_cast<double>(Int128High64(*this)), 64);
            }

            inline int128::operator long double() const {
                // See comment in int128::operator float() above.
                return v_ < 0 && *this != Int128Min()
                       ? -static_cast<long double>(-*this)
                       : static_cast<long double>(Int128Low64(*this)) +
                         std::ldexp(static_cast<long double>(Int128High64(*this)),
                                    64);
            }
#endif  // Clang on PowerPC

// Comparison operators.

            inline bool operator==(int128 lhs, int128 rhs) {
                return static_cast<__int128>(lhs) == static_cast<__int128>(rhs);
            }

            inline bool operator!=(int128 lhs, int128 rhs) {
                return static_cast<__int128>(lhs) != static_cast<__int128>(rhs);
            }

            inline bool operator<(int128 lhs, int128 rhs) {
                return static_cast<__int128>(lhs) < static_cast<__int128>(rhs);
            }

            inline bool operator>(int128 lhs, int128 rhs) {
                return static_cast<__int128>(lhs) > static_cast<__int128>(rhs);
            }

            inline bool operator<=(int128 lhs, int128 rhs) {
                return static_cast<__int128>(lhs) <= static_cast<__int128>(rhs);
            }

            inline bool operator>=(int128 lhs, int128 rhs) {
                return static_cast<__int128>(lhs) >= static_cast<__int128>(rhs);
            }

// Unary operators.

            inline int128 operator-(int128 v) {
                return -static_cast<__int128>(v);
            }

            inline bool operator!(int128 v) {
                return !static_cast<__int128>(v);
            }

            inline int128 operator~(int128 val) {
                return ~static_cast<__int128>(val);
            }

// Arithmetic operators.
            inline int128 operator+(int128 lhs, int128 rhs) {
                return static_cast<__int128>(lhs) + static_cast<__int128>(rhs);
            }
            inline int128 operator-(int128 lhs, int128 rhs) {
                return static_cast<__int128>(lhs) - static_cast<__int128>(rhs);
            }
            inline int128 operator*(int128 lhs, int128 rhs) {
                return static_cast<__int128>(lhs) * static_cast<__int128>(rhs);
            }
            inline int128 operator/(int128 lhs, int128 rhs) {
                return static_cast<__int128>(lhs) / static_cast<__int128>(rhs);
            }
            inline int128 operator%(int128 lhs, int128 rhs) {
                return static_cast<__int128>(lhs) % static_cast<__int128>(rhs);
            }
            inline int128 int128::operator++(int) {
                int128 tmp(*this);
                ++v_;
                return tmp;
            }
            inline int128 int128::operator--(int) {
                int128 tmp(*this);
                --v_;
                return tmp;
            }
            inline int128 &int128::operator++() {
                ++v_;
                return *this;
            }
            inline int128 &int128::operator--() {
                --v_;
                return *this;
            }
            inline int128 operator|(int128 lhs, int128 rhs) {
                return static_cast<__int128>(lhs) | static_cast<__int128>(rhs);
            }
            inline int128 operator&(int128 lhs, int128 rhs) {
                return static_cast<__int128>(lhs) & static_cast<__int128>(rhs);
            }
            inline int128 operator^(int128 lhs, int128 rhs) {
                return static_cast<__int128>(lhs) ^ static_cast<__int128>(rhs);
            }
            inline int128 operator<<(int128 lhs, int amount) {
                return static_cast<__int128>(lhs) << amount;
            }
            inline int128 operator>>(int128 lhs, int amount) {
                return static_cast<__int128>(lhs) >> amount;
            }
        }

_LIB_END_NAMESPACE_STL
#endif //SIMPLE_TEMPLATE_LIBRARY_INT128_H
