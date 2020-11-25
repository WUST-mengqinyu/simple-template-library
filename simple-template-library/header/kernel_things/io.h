//
// Created by badcw on 2020/11/23.
//

#ifndef SIMPLE_TEMPLATE_LIBRARY_IO_H
#define SIMPLE_TEMPLATE_LIBRARY_IO_H

// only file need to import cstdio lib to deal all i/o things (from shell)
#include <cstdio>
#include <header/kernel_things/__config.h>
#include <header/data_structure/base_ds.h>

// namespce IO not stl
namespace IO {
    // need to have read() method
    template<typename T>
    void _R(T &x) { x.read(); }
    void read() {}
    // list read
    template<typename T, typename... U>
    void read(T &head, U &... tail) { __R(head), read(tail...); }

    // need to have write() method
    template<typename T>
    void _W(const T &x) { x.write(); }
    void write() {}
    // list write (space in mid and endl)
    template<typename T, typename... U>
    void write(const T &head, const U &... tail) { _W(head), putchar(sizeof...(tail) ? ' ' : '\n'), write(tail...); }

    // need to have err() method
    template<typename T>
    void _PE(const T &x) { x.err(); }
    void err() {}
    // list perror (space in mid and endl)
    template<typename T, typename... U>
    void err(const T&head, const U &... tail) { _PE(head), perror(sizeof...(tail) ? " " : "\n"); err(tail...); }
}

#endif //SIMPLE_TEMPLATE_LIBRARY_IO_H
