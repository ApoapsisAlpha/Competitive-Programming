#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int MAXN = 100005;

struct Node {
    int m, g, q;
};

int n, m;
int a[MAXN];
Node tree[4*MAXN];

void update(int i) {
    tree[i].m = min(tree[2*i].m, tree[2*i+1].m);
    tree[i].g = __gcd(tree[2*i].g, tree[2*i+1].g);
    tree[i].q = 0;
    if (tree[i].g == tree[2*i].g) tree[i].q += tree[2*i].q;
    if (tree[i].g == tree[2*i+1].g) tree[i].q += tree[2*i+1].q;
}

void build(int i, int l, int r) {
    if (l == r) {
        tree[i].m = tree[i].g = a[l];
        tree[i].q = 1;
        return;
    }

    int mid = (l+r)/2;
    build(2*i, l, mid);
    build(2*i+1, mid+1, r);

    update(i);
}

void change(int i, int l, int r, int x, int v) {
    if (l == r) {
        tree[i].m = tree[i].g = v;
        return;
    }

    int mid = (l+r)/2;
    if (x <= mid) change(2*i, l, mid, x, v);
    else change(2*i+1, mid+1, r, x, v);
    update(i);
}

int mn(int i, int l, int r, int a, int b) {
    if (b < l || a > r) return 0x3f3f3f3f;
    if (a <= l && r <= b) return tree[i].m;

    int mid = (l+r)/2;
    return min(mn(2*i, l, mid, a, b), mn(2*i+1, mid+1, r, a, b));
}

int gcd(int i, int l, int r, int a, int b) {
    if (b < l || a > r) return 0;
    if (a <= l && r <= b) return tree[i].g;

    int mid = (l+r)/2;
    return __gcd(gcd(2*i, l, mid, a, b), gcd(2*i+1, mid+1, r, a, b));
}

int query(int i, int l, int r, int a, int b, int g) {
    if (b < l || a > r) return 0;
    if (a <= l && r <= b) return tree[i].g == g ? tree[i].q : 0;

    int mid = (l+r)/2;
    return query(2*i, l, mid, a, b, g)+query(2*i+1, mid+1, r, a, b, g);
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);
    for (int i = 0; i < m; i++) {
        char c;
        int l, r;
        cin >> c >> l >> r;
        if (c == 'C') {
            change(1, 1, n, l, r);
        }
        else if (c == 'M') {
            cout << mn(1, 1, n, l, r) << '\n';
        }
        else if (c == 'G') {
            cout << gcd(1, 1, n, l, r) << '\n';
        }
        else {
            int g = gcd(1, 1, n, l, r);
            cout << query(1, 1, n, l, r, g) << '\n';
        }
    }
}