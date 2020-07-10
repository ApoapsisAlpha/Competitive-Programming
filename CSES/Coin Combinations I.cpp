#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int MOD = 1e9+7;
int n, x;
int c[105];
int dp[1000005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> c[i];
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (c[j] <= i) {
                dp[i] += dp[i-c[j]];
                if (dp[i] > MOD) dp[i] -= MOD;
            }
        }
    }

    cout << dp[x] << "\n";
}
