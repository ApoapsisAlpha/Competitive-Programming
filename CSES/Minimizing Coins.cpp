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
    cin >> n >> x;
    for (int i = 1; i <= x; i++) dp[i] = INF;
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        for (int j = c; j <= x; j++) {
            dp[j] = min(dp[j], dp[j-c] + 1);
        }
    }

    cout << (dp[x] == INF ? -1 : dp[x]) << "\n";
}
