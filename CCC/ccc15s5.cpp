#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[3002], b[101];
int dp[3002][2][102][102];

int solve(int i, int take, int l, int r) {
    int& res = dp[i][take][l][r];
    if (res != -1) return res;

    if (i == n+1) {
        if (l <= r) {
            if(take)
                return res = b[r] + solve(i, 0, l, r-1);
            return res = solve(i, 1, l+1, r);
        }
        return res = 0;
    }
    if (take) {
        res = max(solve(i, 0, l, r), a[i] + solve(i+1, 0, l, r));
        if (l <= r)
            return res = max(res, b[r] + solve(i, 0, l, r-1));
    }
    else {
        res = solve(i+1, 1, l, r);
        if (l <= r)
            return res = max(res, solve(i, 1, l+1, r));
    }

    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &b[i]);
    }

    sort(b+1, b+1+m);

    memset(dp, -1, sizeof dp);
    printf("%d", solve(1, 1, 1, m));
}