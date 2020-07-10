#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int MOD = 1e9+7;
int n;
int dp[150000];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = n*(n+1)/4; j >= i; j--) {
            dp[j] += dp[j-i];
            if (dp[j] >= MOD) dp[j] -= MOD;
        }
    }

    if (n % 4 == 1 || n % 4 == 2) cout << "0\n";
    else cout << dp[n*(n+1)/4]/2 << "\n";
}
