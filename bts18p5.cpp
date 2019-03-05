#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll a[2001];
ll dp[2001][2001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i <= n; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            dp[i][j] = (dp[i][j-1]+dp[i-1][j-1]*a[j]%998244353)%998244353;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << (dp[i][n]%998244353+998244353)%998244353 << ' ';
    }
}