#include <bits/stdc++.h>
using namespace std;

int n, m;

struct Node {
    int key, p, sz;
    Node* l;
    Node* r;
    Node(int x) : key(x), p(rand()), sz(1) {
        l = r = 0;
    }
};

Node* root;

int sz(Node* n) {
    return n ? n->sz : 0;
}

void updatesz(Node* n) {
    if (!n) return;
    n->sz = 1 + sz(n->l) + sz(n->r);
}

/*
     y         x
    / \       / \
    x C  <-> A   y
   / \          / \
   A  B         B  C
   Right rotation (opposite for left rotation):
   1) Set y's left pointer to x's right pointer (B)
   2) Set x's right pointer to y
   3) Set y to x
*/

void rotright(Node*& y) {
    Node* x = y->l;
    y->l = x->r;
    x->r = y;
    updatesz(y);
    updatesz(x);
    y = x;
}

void rotleft(Node*& x) {
    Node* y = x->r;
    x->r = y->l;
    y->l = x;
    updatesz(x);
    updatesz(y);
    x = y;
}

void ins(Node*& rt, Node* n) {
    if (!rt) {
        rt = n;
    }
    else {
        if (n->key < rt->key) {
            ins(rt->l, n);
            if (rt->p > rt->l->p) rotright(rt);
        }
        else {
            ins(rt->r, n);
            if (rt->p > rt->r->p) rotleft(rt);
        }
    }

    updatesz(rt);
}

void del(Node*& rt, int v) {
    if (!rt) return;
    else {
        if (v == rt->key) {
            if (!rt->l || !rt->r) rt = rt->l ? rt->l : rt->r;
            else {
                if (rt->l->p <= rt->r->p) {
                    rotright(rt);
                    del(rt->r, v);
                }
                else {
                    rotleft(rt);
                    del(rt->l, v);
                }
            }
        }
        else if (v < rt->key) {
            del(rt->l, v);
        }
        else {
            del(rt->r, v);
        }
    }

    updatesz(rt);
}

int smallest(Node* rt, int v) {
    if (!rt) return -2;
    int left = sz(rt->l)+1;
    if (v == left) {
        return rt->key;
    }
    else if (v < left) {
        return smallest(rt->l, v);
    }
    else {
        return smallest(rt->r, v-left);
    }
}

int occurance(Node* rt, int v, int i = 0) {
    if (!rt) return -1;
    if (v == rt->key) {
        int left = occurance(rt->l, v, i);
        if (left == -1) {
            return i+sz(rt->l)+1;
        }
        else {
            return left;
        }
    }
    else if (v < rt->key) {
        return occurance(rt->l, v, i);
    }
    else {
        return occurance(rt->r, v, i+sz(rt->l)+1);
    }
}

void print(Node* rt) {
    if (!rt) return;
    print(rt->l);
    cout << rt->key << " ";
    print(rt->r);
}

int main() {
    srand(time(0));
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ins(root, new Node(x));
    }

    int last = 0;
    for (int i = 0; i < m; i++) {
        char c;
        int v;
        cin >> c >> v;
        v ^= last;
        if (c == 'I') {
            ins(root, new Node(v));
        }
        else if (c == 'R') {
            del(root, v);
        }
        else if (c == 'S') {
            cout << (last = smallest(root, v)) << '\n';
        }
        else {
            cout << (last = occurance(root, v)) << '\n';
        }
    }

    print(root);
}