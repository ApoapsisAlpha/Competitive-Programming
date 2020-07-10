#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int INF = 1e9+5;
int n, x;
int dp[1000005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int cur = i;
        dp[i] = INF;
        while (cur) {
            if (cur%10 <= i) dp[i] = min(dp[i], dp[i-cur%10] + 1);
            cur /= 10;
        }
    }

    cout << dp[n] << "\n";
}


