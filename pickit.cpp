#include <bits/stdc++.h>

using namespace std;

int n;
int k[200];
int dp[200][200];

int solve(int l, int r) {
    if (l == r) return 0;
    if (dp[l][r] == -1) {
        int ans = 0;
        for (int i = l+1; i < r; i++) {
            ans = max(ans, solve(l, i) + solve(i, r) + k[l] + k[i] + k[r]);
        }
        dp[l][r] = ans;
    }

    return dp[l][r];
}

int main() {
    scanf("%d", &n);
    while(n != 0) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &k[i]);
        }

        memset(dp, -1, sizeof dp);
        printf("%d\n", solve(0, n-1));

        scanf("%d", &n);
    }
}