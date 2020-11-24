//
// Created by mengqinyu on 2020/11/23.
//

#ifndef SIMPLE_TEMPLATE_LIBRARY___CONFIG_H
#define SIMPLE_TEMPLATE_LIBRARY___CONFIG_H

#ifndef _LIB_STL_VERSION
#  define _LIB_STL_VERSION 1
#endif

#define _LIB_CONCAT(_LIB_X,_LIB_Y) _LIB_X##_LIB_Y
#define EQUAL(x, y) (x==y)

#ifndef _LIB_ABI_NAMESPACE
# define _LIB_ABI_NAMESPACE _LIB_CONCAT(__,_LIB_ABI_VERSION)
#endif

#define _LIB_TEMPLATE_STL __attribute__ ((__visibility__("default")))
#define _LIB_BEGIN_NAMESPACE_STL namespace stl { inline namespace _LIB_ABI_NAMESPACE {
#define _LIB_END_NAMESPACE_STL  } }

#define force_inline __inline__ __attribute__((always_inline))
#endif //SIMPLE_TEMPLATE_LIBRARY___CONFIG_H
