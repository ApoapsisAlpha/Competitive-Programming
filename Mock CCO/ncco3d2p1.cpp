#include <bits/stdc++.h>
using namespace std;

#define MAXN 50001

struct node {
    int l, r, mn, mx;
};

int n, q;
int arr[MAXN];
node tree[4*MAXN];

void build(int i, int a, int b) {
    tree[i].l = a;
    tree[i].r = b;

    if (a == b) {
        tree[i].mn = tree[i].mx = arr[a];
        return;
    }

    int mid = (a+b)/2;
    build(2*i, a, mid);
    build(2*i+1, mid+1, b);

    tree[i].mn = min(tree[2*i].mn, tree[2*i+1].mn);
    tree[i].mx = max(tree[2*i].mx, tree[2*i+1].mx);
}

pair<int, int> query(int i, int a, int b) {
    if (b < tree[i].l || a > tree[i].r) return { 0x3f3f3f3f, 0 };
    if (a <= tree[i].l && tree[i].r <= b) return { tree[i].mn, tree[i].mx };

    pair<int, int> left = query(2*i, a, b);
    pair<int, int> right = query(2*i+1, a, b);

    return { min(left.first, right.first), max(left.second, right.second) };
}

int main() {
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }

    build(1, 1, n);

    for (int i = 0; i < q; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        pair<int, int> x = query(1, a, b);
        printf("%d\n", x.second-x.first);
    }

}