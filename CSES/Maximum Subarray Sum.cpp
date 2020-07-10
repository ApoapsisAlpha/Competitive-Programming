#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n;
ll ans, cur;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ans = -1e18;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        cur = max(cur+x, x);
        ans = max(ans, cur);
    }

    cout << ans << "\n";
}

