#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int h, w;
int g[1001][1001];
int dp[1001][1001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> h >> w;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            char c;
            cin >> c;
            if (c == '.') g[i][j] = 1;
            else g[i][j] = 0;
        }
    }

    dp[1][1] = 1;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (i == 1 && j == 1) continue;
            if (g[i][j]) {
                dp[i][j] = (dp[i-1][j] + dp[i][j-1])%1000000007;
            }
        }
    }

    printf("%d\n", dp[h][w]);
}