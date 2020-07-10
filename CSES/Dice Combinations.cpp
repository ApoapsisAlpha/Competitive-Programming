#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int mod = 1e9+7;
int n;
int dp[1000005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 6 && j <= i; j++) {
            dp[i] += dp[i-j];
            if (dp[i] > mod) dp[i] -= mod;
        }
    }

    cout << dp[n] << "\n";
}
