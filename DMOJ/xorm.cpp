#include <bits/stdc++.h>
using namespace std;

struct Node {
    int i;
    Node* c[2];
    Node() : i(0x3f3f3f3f) {}
};

int n, q;
Node* root;

void insert(Node* rt, int v, int i) {
    for (int i = 31; i >= 0; i--) {
        bool bit = v&(1<<i);
        if (!rt->c[bit]) rt->c[bit] = new Node;
        rt = rt->c[bit];
    }

    rt->i = min(rt->i, i);
}

int query(Node* rt, int x) {
    for (int i = 31; i >= 0; i--) {
        bool bit = x&(1<<i);
        if (rt->c[bit]) rt = rt->c[bit];
        else if (rt->c[!bit]) rt = rt->c[!bit];
    }

    return rt->i;
}

int main() {
    scanf("%d %d", &n, &q);
    root = new Node;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        insert(root, x, i);
    }

    int v = 0;
    for (int i = 0; i < q; i++) {
        int x;
        scanf("%d", &x);
        v ^= x;
        printf("%d\n", query(root, v));
    }
}