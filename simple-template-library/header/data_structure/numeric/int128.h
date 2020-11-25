//
// Created by mengqinyu on 2020/11/25.
//

#ifndef SIMPLE_TEMPLATE_LIBRARY_INT128_H
#define SIMPLE_TEMPLATE_LIBRARY_INT128_H

#include <header/kernel_things/__config.h>
#include <ostream>

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
        uint128& operator=(__int128 v);
  uint128& operator=(unsigned __int128 v);
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
        friend H AbslHashValue(H h, uint128 v) {
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
    std::ostream& operator<<(std::ostream& os, uint128 v);

    constexpr uint128 Uint128Max() {
        return uint128((std::numeric_limits<uint64_t>::max)(),
                       (std::numeric_limits<uint64_t>::max)());
    }
} // namespace __INTERNAL

// Spcialized numeric_limits for uint128
namespace std {
    template <>
    class numeric_limits<__INTERNAL::uint128> {
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

        static constexpr __INTERNAL::uint128(min)() { return 0; }
        static constexpr __INTERNAL::uint128 lowest() { return 0; }
        static constexpr __INTERNAL::uint128(max)() { return __INTERNAL::Uint128Max(); }
        static constexpr __INTERNAL::uint128 epsilon() { return 0; }
        static constexpr __INTERNAL::uint128 round_error() { return 0; }
        static constexpr __INTERNAL::uint128 infinity() { return 0; }
        static constexpr __INTERNAL::uint128 quiet_NaN() { return 0; }
        static constexpr __INTERNAL::uint128 signaling_NaN() { return 0; }
        static constexpr __INTERNAL::uint128 denorm_min() { return 0; }
    };
}  // namespace std

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
        int128& operator=(int v);
        int128& operator=(unsigned int v);
        int128& operator=(long v);                // NOLINT(runtime/int)
        int128& operator=(unsigned long v);       // NOLINT(runtime/int)
        int128& operator=(long long v);           // NOLINT(runtime/int)
        int128& operator=(unsigned long long v);  // NOLINT(runtime/int)
#ifdef STL_HAVE_INTRINSIC_INT128
        int128& operator=(__int128 v);
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
        int128& operator+=(int128 other);
        int128& operator-=(int128 other);
        int128& operator*=(int128 other);
        int128& operator/=(int128 other);
        int128& operator%=(int128 other);
        int128 operator++(int);  // postfix increment: i++
        int128 operator--(int);  // postfix decrement: i--
        int128& operator++();    // prefix increment:  ++i
        int128& operator--();    // prefix decrement:  --i
        int128& operator&=(int128 other);
        int128& operator|=(int128 other);
        int128& operator^=(int128 other);
        int128& operator<<=(int amount);
        int128& operator>>=(int amount);

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

    std::ostream& operator<<(std::ostream& os, int128 v);

    constexpr int128 Int128Max() {
        return int128((std::numeric_limits<int64_t>::max)(),
                      (std::numeric_limits<uint64_t>::max)());
    }

    constexpr int128 Int128Min() {
        return int128((std::numeric_limits<int64_t>::min)(), 0);
    }
} // namespace __INTERNAL

// Specialized numeric_limits for int128.
namespace std {
    template <>
    class numeric_limits<__INTERNAL::int128> {
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
#ifdef ABSL_HAVE_INTRINSIC_INT128
        static constexpr bool traps = numeric_limits<__int128>::traps;
#else  // ABSL_HAVE_INTRINSIC_INT128
        static constexpr bool traps = numeric_limits<uint64_t>::traps;
#endif  // ABSL_HAVE_INTRINSIC_INT128
        static constexpr bool tinyness_before = false;
        static constexpr __INTERNAL::int128(min)() { return __INTERNAL::Int128Min(); }
        static constexpr __INTERNAL::int128 lowest() { return __INTERNAL::Int128Min(); }
        static constexpr __INTERNAL::int128(max)() { return __INTERNAL::Int128Max(); }
        static constexpr __INTERNAL::int128 epsilon() { return 0; }
        static constexpr __INTERNAL::int128 round_error() { return 0; }
        static constexpr __INTERNAL::int128 infinity() { return 0; }
        static constexpr __INTERNAL::int128 quiet_NaN() { return 0; }
        static constexpr __INTERNAL::int128 signaling_NaN() { return 0; }
        static constexpr __INTERNAL::int128 denorm_min() { return 0; }
    };
}  // namespace std

// --------------------------------------------------------------------------
//                      Implementation details follow
// --------------------------------------------------------------------------

#endif //SIMPLE_TEMPLATE_LIBRARY_INT128_H
