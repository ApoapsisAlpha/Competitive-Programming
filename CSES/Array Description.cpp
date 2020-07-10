#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int MOD = 1e9+7;
int n, m;
ll dp[105];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int x;
    cin >> x;
    if (x) dp[x] = 1;
    else {
        for (int i = 1; i <= m; i++) dp[i] = 1;
    }

    for (int i = 1; i < n; i++) {
        cin >> x;
        if (x) {
            dp[x] = (dp[x-1] + dp[x] + dp[x+1])%MOD;
            for (int j = 1; j <= m; j++) {
                if (j != x) dp[j] = 0;
            }
        }
        else {
            vector<ll> prev(m+1);
            for (int j = 0; j <= m+1; j++) prev[j] = dp[j];
            for (int j = 1; j <= m; j++) {
                dp[j] = (prev[j-1] + prev[j] + prev[j+1])%MOD;
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= m; i++) ans = (ans + dp[i])%MOD;
    cout << ans << "\n";
}
