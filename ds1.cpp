#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
int arr[100001];
ll sumtree[100001];
int freqtree[100001];

void updatesum(int i, int v) {
    while (i <= 100000) {
        sumtree[i] += v;
        i += (-i)&i;
    }
}

void updatefreq(int i, int v) {
    while (i <= 100000) {
        freqtree[i] += v;
        i += (-i)&i;
    }
}

ll sumq(int i) {
    ll sum = 0;
    while (i > 0) {
        sum += sumtree[i];
        i -= (-i)&i;
    }

    return sum;
}

int freq(int i) {
    int sum = 0;
    while (i > 0) {
        sum += freqtree[i];
        i -= (-i)&i;
    }

    return sum;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int x, i = 1; i <= n; i++) {
        cin >> x;
        updatesum(i, x);
        updatefreq(x, 1);
        arr[i] = x;
    }

    for (int i = 1; i <= m; i++) {
        char c;
        cin >> c;
        if (c == 'C') {
            int x, v;
            cin >> x >> v;
            updatefreq(arr[x], -1);
            updatefreq(v, 1);
            updatesum(x, v-arr[x]);
            arr[x] = v;
        }
        else if (c == 'S') {
            int l, r;
            cin >> l >> r;
            cout << sumq(r)-sumq(l-1) << '\n';
        }
        else if (c == 'Q') {
            int v;
            cin >> v;
            cout << freq(v) << '\n';
        }
    }
}