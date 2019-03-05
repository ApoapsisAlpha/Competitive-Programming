#include <bits/stdc++.h>

using namespace std;

int r, c, k;
int dp[27][27];

int main() {
    scanf("%d%d%d", &r, &c, &k);
    dp[1][1] = 1;

    for (int i = 1; i <= k; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        dp[x][y] = -1;
    }

    for (int i = 1; i <= r; i++) {
        for (int j = 1; j <= c; j++) {
            if (i == 1 && j == 1 || dp[i][j] == -1) continue;
            int c = 0;
            if (dp[i-1][j] != -1) c += dp[i-1][j];
            if (dp[i][j-1] != -1) c += dp[i][j-1];
            dp[i][j] = c;
        }
    }

    printf("%d\n", dp[r][c]);
}