//
// Created by badcw on 2020/11/20.
//

#ifndef SIMPLE_TEMPLATE_LIBRARY_RB_TREE_H
#define SIMPLE_TEMPLATE_LIBRARY_RB_TREE_H

struct Node {
    int data, s, c;
    bool color;
    Node *fa, *ch[2];
    fast void set( const int & _v, const bool & _color, const int & i, register Node * p) {
        data = _v, color = _color, s = c = i;
        fa = ch[0] = ch[1] = p;
    }
    fast void push_up() {
        s = ch[0]->s + ch[1]->s + c;
    }
    fast void push_down() {
        for (Node *x = this; x->s; x = x->fa) x->s--;
    }
    fast int cmp( const int & v) const {
        return data == v ? -1 : v > data;
    }
};
struct RedBlackTree {
    int top;
    Node *root, *null;
    Node stack[Max_N], *tail, *store[Max_N];
    fast void init() {
        tail = &stack[0];
        null = tail++;
        null->set(0, 0, 0, NULL);
        root = null;
        top = 0;
    }
    fast Node *newNode( const int & v) {
        register Node *p = null;
        if (!top) p = tail++;
        else p = store[--top];
        p->set(v, 1, 1, null);
        return p;
    }
    fast void rotate( register Node* &x, const bool & d ) {
        register Node *y = x->ch[!d];
        x->ch[!d] = y->ch[d];
        if (y->ch[d]->s) y->ch[d]->fa = x;
        y->fa = x->fa;
        if (!x->fa->s) root = y;
        else x->fa->ch[x->fa->ch[0] != x] = y;
        y->ch[d] = x;
        x->fa = y;
        y->s = x->s;
        x->push_up();
    }
    fast void insert( const int & v) {
        register Node *x = root, *y = null;
        while (x->s) {
            x->s++, y = x;
            int d = x->cmp(v);
            if (-1 == d) {
                x->c++;
                return;
            }
            x = x->ch[d];
        }
        x = newNode(v);
        if (y->s) y->ch[v > y->data] = x;
        else root = x;
        x->fa = y;
        insert_fix(x);
    }
    fast void insert_fix( register Node* &x) {
        while (x->fa->color) {
            Node *par = x->fa, *Gp = par->fa;
            bool d = par == Gp->ch[0];
            Node *uncle = Gp->ch[d];
            if (uncle->color) {
                par->color = uncle->color = 0;
                Gp->color = 1;
                x = Gp;
            } else if (x == par->ch[d]) {
                rotate(x = par, !d);
            } else {
                Gp->color = 1;
                par->color = 0;
                rotate(Gp, d);
            }
        }
        root->color = 0;
    }
    fast Node *find(Node *x, int data) {
        while (x->s && x->data != data) x = x->ch[x->data < data];
        return x;
    }
    fast void del_fix( register Node * &x) {
        while (x != root && !x->color) {
            register bool d = x == x->fa->ch[0];
            Node *par = x->fa, *sibling = par->ch[d];
            if (sibling->color) {
                sibling->color = 0;
                par->color = 1;
                rotate(x->fa, !d);
                sibling = par->ch[d];
            } else if (!sibling->ch[0]->color && !sibling->ch[1]->color) {
                sibling->color = 1, x = par;
            } else {
                if (!sibling->ch[d]->color) {
                    sibling->ch[!d]->color = 0;
                    sibling->color = 1;
                    rotate(sibling, d);
                    sibling = par->ch[d];
                }
                sibling->color = par->color;
                sibling->ch[d]->color = par->color = 0;
                rotate(par, !d);
                break;
            }
        }
        x->color = 0;
    }
    fast void del( const int & data) {
        register Node *z = find(root, data);
        if (!z->s) return;
        if (z->c > 1) {
            z->c--;
            z->push_down();
            return;
        }
        register Node *y = z, *x = null;
        if (z->ch[0]->s && z->ch[1]->s) {
            y = z->ch[1];
            while (y->ch[0]->s) y = y->ch[0];
        }
        x = y->ch[!y->ch[0]->s];
        x->fa = y->fa;
        if (!y->fa->s) root = x;
        else y->fa->ch[y->fa->ch[1] == y] = x;
        if (z != y) z->data = y->data, z->c = y->c;
        y->fa->push_down();
        for (Node *k = y->fa; y->c > 1 && k->s && k != z; k = k->fa) k->s -= y->c - 1;
        if (!y->color) del_fix(x);
        store[top++] = y;
    }
    fast void kth( register int k) {
        register int t;
        register Node *x = root;
        for (; x->s;) {
            t = x->ch[0]->s;
            if (k <= t) x = x->ch[0];
            else if (t + 1 <= k && k <= t + x->c) break;
            else k -= t + x->c, x = x->ch[1];
        }
        ip.println(x->data);
    }
    fast void rank( const int & v) {
        register int t, cur = 0;
        register Node *x = root;
        for (; x->s;) {
            t = x->ch[0]->s;
            if (v == x->data) break;
            else if (v < x->data) x = x->ch[0];
            else cur += t + x->c, x = x->ch[1];
        }
        ip.println(cur + t + 1);
    }
    fast void succ( const int & v) {
        int ret = 0;
        Node *x = root;
        while (x->s) {
            if (x->data > v) ret = x->data, x = x->ch[0];
            else x = x->ch[1];
        }
        ip.println(ret);
    }
    fast void pred( const int & v) {
        register int ret = 0;
        register Node *x = root;
        while (x->s) {
            if (x->data < v) ret = x->data, x = x->ch[1];
            else x = x->ch[0];
        }
        ip.println(ret);
    }
}rbt;

#endif //SIMPLE_TEMPLATE_LIBRARY_RB_TREE_H
