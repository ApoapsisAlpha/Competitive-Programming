#include <bits/stdc++.h>
using namespace std;

int dp[251][251][251];

int solve(int n, int k, int mn) {
    if (k == 1 || n == k) return 1;
    if (dp[n][k][mn]) return dp[n][k][mn];

    int res = 0;
    for (int i = mn; i <= n/k; i++) {
        res += solve(n-i, k-1, i);
    }

    return dp[n][k][mn] = res;
}

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    printf("%d\n", solve(n, k, 1));
}