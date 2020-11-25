//
// Created by mengqinyu on 2020/11/24.
//

#ifndef SIMPLE_TEMPLATE_LIBRARY_BASE_DS_H
#define SIMPLE_TEMPLATE_LIBRARY_BASE_DS_H

#include <header/kernel_things/__config.h>
#include <cstdio>

_LIB_BEGIN_NAMESPACE_STL

        class int128 {
            int x;
        };

        template<typename T>
        class modInt {
        };

        template<class T, class U>
        bool __IsSameType() {
            return false;
        };

        template<class T>
        bool __IsSameType() {
            return true;
        }

        template<typename T>
        class baseDataStructure {
            T __val;
            void print() {
                if (__IsSameType<T, int>) {

                }
            }
        };

        typedef baseDataStructure<unsigned int> uint;
        typedef baseDataStructure<long long> int64;
        typedef baseDataStructure<unsigned long long> uint64;
        typedef modInt<int> modint;
        typedef modInt<int64> modint64;


_LIB_END_NAMESPACE_STL

#endif //SIMPLE_TEMPLATE_LIBRARY_BASE_DS_H
