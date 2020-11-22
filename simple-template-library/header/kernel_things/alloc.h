//
// Created by badcw on 2020/11/23.
//

#ifndef SIMPLE_TEMPLATE_LIBRARY_ALLOC_H
#define SIMPLE_TEMPLATE_LIBRARY_ALLOC_H

#pragma once
#define MIN_ALLOC 0

extern const unsigned int POINTER_SIZE = sizeof(void *);

typedef void *memory_resource;

static memory_resource MEMORY_POOL;

template<typename T>
class alloc {
    alloc(int _sz = 0);
};

template<typename T>
alloc<T>::alloc(int _sz) {
}


#endif //SIMPLE_TEMPLATE_LIBRARY_ALLOC_H
