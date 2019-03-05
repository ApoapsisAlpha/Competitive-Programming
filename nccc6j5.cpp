#include <bits/stdc++.h>
using namespace std;

int n, k;
long long ans;
int cur[1001];
int a[1001];
int b[1001];
int dp[1001][1001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a, a+n+1);
    for (int i = 1; i <= n; i++) {
        dp[1][i] = i;
    }

    for (int i = 2; i <= k; i++) {
        int cur = 0;
        for (int j = i; j <= n; j++) {
            if (a[j]^a[j-1]) cur = j-1;
            dp[i][j] = (dp[i][j-1]+dp[i-1][cur])%998244353;
        }
    }

    cout << dp[k][n] << '\n';
}