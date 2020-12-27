//
// Created by mengqinyu on 2020/11/24.
//

#ifndef SIMPLE_TEMPLATE_LIBRARY_BASE_DS_H
#define SIMPLE_TEMPLATE_LIBRARY_BASE_DS_H

#include <header/kernel_things/__config.h>
#include <header/data_structure/numeric/int128.h>
#include <header/data_structure/numeric/modInt.h>
#include <cstdio>

_LIB_BEGIN_NAMESPACE_STL

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
//        typedef __INTERNAL::modInt<int> modint;
//        typedef __INTERNAL::modInt<int64> modint64;
        typedef __INTERNAL::int128 int128;
        typedef __INTERNAL::uint128 uint128;

_LIB_END_NAMESPACE_STL

#endif //SIMPLE_TEMPLATE_LIBRARY_BASE_DS_H
