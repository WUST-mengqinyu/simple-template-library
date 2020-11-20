//
// Created by badcw on 2020/11/15.
//

#ifndef SIMPLE_TEMPLATE_LIBRARY_LINK_LIST_H
#define SIMPLE_TEMPLATE_LIBRARY_LINK_LIST_H

namespace simple_template_library {
    template<typename T>
    class link_list {
    };

    template<typename T>
    struct node {
        T val;
        node *nxt;
        node() = default;
        node(T _val): val(_val) {}

        node(T _val, node *_nxt): val(_val), nxt(_nxt) {}
    };
    struct iterator {
    };
}

#endif //EASY_TEMPLATE_LIBRARY_LINK_LIST_H