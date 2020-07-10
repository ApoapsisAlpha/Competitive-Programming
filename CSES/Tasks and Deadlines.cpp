#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n;
ll  ans;
pii a[200005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = make_pair(x, y);
    }

    sort(a, a+n);
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        cur += a[i].first;
        ans += a[i].second - cur;
    }

    cout << ans << "\n";
}
