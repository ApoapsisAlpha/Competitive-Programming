#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n, ans;
int dp[200005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int j = lower_bound(dp, dp+ans, x) - dp;
        if (j == ans) ans++;
        dp[j] = x;
    }

    cout << ans << "\n";
}

