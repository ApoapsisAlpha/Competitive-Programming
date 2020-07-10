#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int MOD = 1e9+7;
int n, x;
int dp[1000005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        for (int j = c; j <= x; j++) {
            dp[j] += dp[j-c];
            if (dp[j] > MOD) dp[j] -= MOD;
        }
    }

    cout << dp[x] << "\n";
}

