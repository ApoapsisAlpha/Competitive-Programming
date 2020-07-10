#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int MOD = 1e9+7;
int n, x;
int dp[1005][1005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    dp[0][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char c;
            cin >> c;
            if (c == '*') dp[i][j] = 0;
            else dp[i][j] = dp[i-1][j] + dp[i][j-1];
            if (dp[i][j] >= MOD) dp[i][j] -= MOD;
        }
    }

    cout << dp[n][n] << "\n";
}

