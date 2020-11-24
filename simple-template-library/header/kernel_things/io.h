//
// Created by badcw on 2020/11/23.
//

#ifndef SIMPLE_TEMPLATE_LIBRARY_IO_H
#define SIMPLE_TEMPLATE_LIBRARY_IO_H

// only file need to import cstdio lib to deal all i/o things (from shell)
#include <cstdio>

namespace IO {
    void __R(char &x);
    void __R(int &x);
    void __R(long long &x);
    void __R(int128 &x);
    void _R(int &x) { scanf("%d", &x); }
    void _R(double &x) { scanf("%lf", &x); }

    void _R(char &x) { x = getchar(); }

    void _R(char *x) { scanf("%s", x); }

    void R() {}

    template<class T, class... U>
    void R(T &head, U &... tail) { _R(head), R(tail...); }

    template<class T>
    void _W(const T &x) { cout << x; }

    void _W(const int &x) { printf("%d", x); }

    void _W(const ll &x) { printf("%lld", x); }

    void _W(const double &x) { printf("%.16f", x); }

    void _W(const char &x) { putchar(x); }

    void _W(const char *x) { printf("%s", x); }

    template<class T, class U>
    void _W(const pair <T, U> &x) { _W(x.first), putchar(' '), _W(x.second); }

    template<class T>
    void _W(const vector <T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }

    void W() {}

    template<class T, class... U>
    void W(const T &head, const U &... tail) { _W(head), putchar(sizeof...(tail) ? ' ' : '\n'), W(tail...); }
}

#endif //SIMPLE_TEMPLATE_LIBRARY_IO_H
