//
// Created by mengqinyu on 2020/11/24.
//

#ifndef SIMPLE_TEMPLATE_LIBRARY_INTEGER_H
#define SIMPLE_TEMPLATE_LIBRARY_INTEGER_H

#include <header/kernel_things/__config.h>

_LIB_BEGIN_NAMESPACE_STL

#define int int
#define uint unsigned int
#define int64 long long
#define uint64 usigned int64
#define int128 __Int128
#define modint __modInt<int>
#define modint64 __modInt<int64>

class __Int128 {
    ;
};

template<typename T>
class __modInt {
};

_LIB_END_NAMESPACE_STL

#endif //SIMPLE_TEMPLATE_LIBRARY_INTEGER_H
