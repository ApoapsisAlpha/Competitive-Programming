#include <bits/stdc++.h>
using namespace std;

#define MAXN 30001

struct node {
    int l, r;
    long long val, lz;
};

int n, q;
int arr[MAXN];
node tree[4*MAXN];

void pushdown(int i) {
    tree[2*i].lz += tree[i].lz;
    tree[2*i+1].lz += tree[i].lz;
    tree[i].lz = 0;
}

void update(int i) {
    node left = tree[2*i];
    node right = tree[2*i+1];
    tree[i].val = min(max(0LL, left.val-left.lz), max(0LL, right.val-right.lz));
}

void build(int i, int a, int b) {
    tree[i].l = a;
    tree[i].r = b;

    if (a == b) {
        tree[i].val = arr[a];
        return;
    }

    int mid = (a+b)/2;
    build(2*i, a, mid);
    build(2*i+1, mid+1, b);

    update(i);
}

void decrement(int i, int a, int b, int v) {
    if (b < tree[i].l || a > tree[i].r) return;

    if (a <= tree[i].l && tree[i].r <= b) {
        tree[i].lz += v;
        return;
    }

    pushdown(i);

    decrement(2*i, a, b, v);
    decrement(2*i+1, a, b, v);

    update(i);
}

long long query(int i, int a, int b) {
    if (b < tree[i].l || a > tree[i].r) return 10000000000000000L;
    if (a <= tree[i].l && tree[i].r <= b) return max(0LL, tree[i].val-tree[i].lz);

    pushdown(i);
    long long left = query(2*i, a, b);
    long long right = query(2*i+1, a, b);

    update(i);
    return min(max(0LL, left), max(0LL, right));
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    build(1, 1, n);
    for (int i = 0; i < q; i++) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        decrement(1, a, b, c);
        printf("%lld %lld\n", query(1, a, b), max(0LL, tree[1].val-tree[1].lz));
    }
}