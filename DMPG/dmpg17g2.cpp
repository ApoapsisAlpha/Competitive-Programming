#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

struct Node {
    ll sum, mx, pre, suf;
};

const int MAXN = 100005;

int n, q;
int a[MAXN];
Node tree[4*MAXN];

Node update(Node l, Node r) {
    Node n;
    n.sum = l.sum+r.sum;
    n.pre = max(l.pre, l.sum+r.pre);
    n.suf = max(r.suf, r.sum+l.suf);
    n.mx = max(max(l.mx, r.mx), l.suf+r.pre);
    return n;
}

void build(int i, int l, int r) {
    if (l == r) {
        tree[i].sum = tree[i].mx = tree[i].pre = tree[i].suf = a[l];
        return;
    }

    int mid = (l+r)/2;
    build(i<<1, l, mid);
    build(i<<1|1, mid+1, r);

    tree[i] = update(tree[i<<1], tree[i<<1|1]);
}

void change(int i, int l, int r, int x, int v) {
    if (l == r) {
        tree[i].sum = tree[i].mx = tree[i].pre = tree[i].suf = v;
        return;
    }

    int mid = (l+r)/2;
    if (x <= mid) change(i<<1, l, mid, x, v);
    else change(i<<1|1, mid+1, r, x, v);

    tree[i] = update(tree[i<<1], tree[i<<1|1]);
}

Node query(int i, int l, int r, int a, int b) {
    Node res;
    res.sum = res.mx = res.pre = res.suf = -1e18L;
    if (b < l || a > r) return res;
    if (a <= l && r <= b) return tree[i];

    int mid = (l+r)/2;
    if (b <= mid) return query(i<<1, l, mid, a, b);
    if (a > mid) return query(i<<1|1, mid+1, r, a, b);

    Node left = query(i<<1, l, mid, a, b);
    Node right = query(i<<1|1, mid+1, r, a, b);
    res = update(left, right);
    return res;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    build(1, 1, n);
    for (int i = 0; i < q; i++) {
        char c;
        int l, r;
        cin >> c >> l >> r;
        if (c == 'S') {
            change(1, 1, n, l, r);
        }
        else {
            cout << query(1, 1, n, l, r).mx << '\n';
        }
    }
}