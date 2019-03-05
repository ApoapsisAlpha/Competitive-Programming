#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct query {
    int i, l, r, m;

    bool operator<(const query& q) {
        if (m == q.m) {
            return i < q.i;
        }
        return m > q.m;
    }
};

int n, q;
query a[200005];
int tree[100002];
int ans[100002];

void update(int i, int v) {
    while (i <= n) {
        tree[i] += v;
        i += (i & -i);
    }
}

int sum(int i) {
    int sum = 0;
    while (i) {
        sum += tree[i];
        i -= (i & -i);
    }

    return sum;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].m;
        a[i].r = i+1;
        a[i].l = 0;
        a[i].i = 0;
    }

    cin >> q;
    for (int i = n; i < n+q; i++) {
        int l, r, m;
        cin >> l >> r >> m;
        a[i].i = i-n+1;
        a[i].l = l;
        a[i].r = r;
        a[i].m = m;
    }

    sort(a, a+n+q);

    for (int i = 0; i < n+q; i++) {
        if (a[i].i != 0) {
            ans[a[i].i] = sum(a[i].r+1)-sum(a[i].l);
        }
        else {
            update(a[i].r, a[i].m);
        }
    }

    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
    }
}