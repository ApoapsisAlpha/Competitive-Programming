#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n;
ll dp[200005];
pair<pii, int> a[200005];

bool cmp(pair<pii, int> p1, pair<pii, int> p2) {
    if (p1.first.second == p2.first.second) return p1.first.first < p2.first.first;
    return p1.first.second < p2.first.second;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int l, r, p;
        cin >> l >> r >> p;
        a[i] = make_pair(make_pair(l, r), p);
    }

    sort(a+1, a+n+1, cmp);
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i-1, j = 0;
        while (l <= r) {
            int m = l + (r-l)/2;
            if (a[m].first.second < a[i].first.first) {
                j = m;
                l = m+1;
            }
            else r = m-1;
        }

        dp[i] = max(dp[i-1], dp[j] + a[i].second);
    }

    cout << dp[n] << "\n";
}
