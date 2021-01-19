//
// Created by mengqinyu on 2020/11/23.
//

#ifndef SIMPLE_TEMPLATE_LIBRARY___CONFIG_H
#define SIMPLE_TEMPLATE_LIBRARY___CONFIG_H

#ifndef _LIB_STL_VERSION
#define _LIB_STL_VERSION 1
#endif

#define _LIB_CONCAT(_LIB_X, _LIB_Y) _LIB_X##_LIB_Y
#define EQUAL(x, y) (x==y)

#ifndef _LIB_ABI_NAMESPACE
#define _LIB_ABI_NAMESPACE _LIB_CONCAT(__,_LIB_STL_VERSION)
#endif

// define namespace begin and end
#define _LIB_TEMPLATE_STL __attribute__ ((__visibility__("default")))
#define _LIB_BEGIN_NAMESPACE_STL namespace stl { inline namespace _LIB_ABI_NAMESPACE {
#define _LIB_END_NAMESPACE_STL  } }

//#define force_inline inline
//#define force_inline __inline__ __attribute__((always_inline))

// STL_HAVE_INTRINSIC_INT128
//
// Checks whether the __int128 compiler extension for a 128-bit integral type is
// supported.
//
// Note: __SIZEOF_INT128__ is defined by Clang and GCC when __int128 is
// supported, but we avoid using it in certain cases:
// * On Clang:
//   * Building using Clang for Windows, where the Clang runtime library has
//     128-bit support only on LP64 architectures, but Windows is LLP64.
// * On Nvidia's nvcc:
//   * nvcc also defines __GNUC__ and __SIZEOF_INT128__, but not all versions
//     actually support __int128.

#ifdef STL_HAVE_INTRINSIC_INT128
#error STL_HAVE_INTRINSIC_INT128 cannot be directly set
#elif defined(__SIZEOF_INT128__)
#if (defined(__clang__) && !defined(_WIN32)) || \
    (defined(__CUDACC__) && __CUDACC_VER_MAJOR__ >= 9) || \
    (defined(__GNUC__) && !defined(__clang__) && !defined(__CUDACC__))
#define STL_HAVE_INTRINSIC_INT128 1
#elif defined(__CUDACC__)
// __CUDACC_VER__ is a full version number before CUDA 9, and is defined to a
// string explaining that it has been removed starting with CUDA 9. We use
// nested #ifs because there is no short-circuiting in the preprocessor.
// NOTE: `__CUDACC__` could be undefined while `__CUDACC_VER__` is defined.
#if __CUDACC_VER__ >= 70000
#define STL_HAVE_INTRINSIC_INT128 1
#endif  // __CUDACC_VER__ >= 70000
#endif  // defined(__CUDACC__)
#endif  // STL_HAVE_INTRINSIC_INT128


// STL_IS_LITTLE_ENDIAN
// STL_IS_BIG_ENDIAN
//
// Checks the endianness of the platform.
//
// Notes: uses the built in endian macros provided by GCC (since 4.6) and
// Clang (since 3.2); see
// https://gcc.gnu.org/onlinedocs/cpp/Common-Predefined-Macros.html.
// Otherwise, if _WIN32, assume little endian. Otherwise, bail with an error.
#if defined(STL_IS_BIG_ENDIAN)
#error "STL_IS_BIG_ENDIAN cannot be directly set."
#endif
#if defined(STL_IS_LITTLE_ENDIAN)
#error "STL_IS_LITTLE_ENDIAN cannot be directly set."
#endif

#if (defined(__BYTE_ORDER__) && defined(__ORDER_LITTLE_ENDIAN__) && \
     __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)
#define STL_IS_LITTLE_ENDIAN 1
#elif defined(__BYTE_ORDER__) && defined(__ORDER_BIG_ENDIAN__) && \
    __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
#define STL_IS_BIG_ENDIAN 1
#elif defined(_WIN32)
#define STL_IS_LITTLE_ENDIAN 1
#else
#error "STL endian detection needs to be set up for your compiler"
#endif

// STL_DLL
//
// When building Abseil as a DLL, this macro expands to `__declspec(dllexport)`
// so we can annotate symbols appropriately as being exported. When used in
// headers consuming a DLL, this macro expands to `__declspec(dllimport)` so
// that consumers know the symbol is defined inside the DLL. In all other cases,
// the macro expands to nothing.
#if defined(_MSC_VER)
#if defined(STL_BUILD_DLL)
#define STL_DLL __declspec(dllexport)
#elif defined(STL_CONSUME_DLL)
#define STL_DLL __declspec(dllimport)
#else
#define STL_DLL
#endif
#else
#define STL_DLL
#endif  // defined(_MSC_VER)

#endif //SIMPLE_TEMPLATE_LIBRARY___CONFIG_H
