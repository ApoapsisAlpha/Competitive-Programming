#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
ll dp[3001][3001];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &dp[i][i]);
    }

    for (int l = n; l; l--) {
        for (int r = l+1; r <= n; r++) {
            dp[l][r] = max(dp[l][l]-dp[l+1][r], dp[r][r]-dp[l][r-1]);
        }
    }

    printf("%lld\n", dp[1][n]);
}