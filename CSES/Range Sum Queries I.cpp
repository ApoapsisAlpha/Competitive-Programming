#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n, q;
ll pre[200005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> pre[i];
        pre[i] += pre[i-1];
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        cout << pre[b] - pre[a-1] << "\n";
    }
}
