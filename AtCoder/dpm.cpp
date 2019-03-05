#include <bits/stdc++.h>
using namespace std;

int n, k;
int a[101];
int dp[101][100001];
int psa[101][100001];

int main() {
    scanf("%d %d", &n, &k);
    dp[0][0] = psa[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        dp[i][0] = psa[i][0] = 1;
    }

    for (int i = 1; i <= k; i++) psa[0][i] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            int l = j-a[i]-1 >= 0 ? psa[i-1][j-a[i]-1] : 0;
            int r = psa[i-1][j];
            dp[i][j] = r-l;
            if (dp[i][j] < 0) dp[i][j] += 1000000007;
            psa[i][j] = (psa[i][j-1] + dp[i][j])%1000000007;
        }
    }

    printf("%d\n", dp[n][k]);
}