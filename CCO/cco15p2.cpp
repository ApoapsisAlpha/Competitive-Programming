#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int n, m;
vector<pii> adj[20];
int dp[20][1<<20];

int solve(int u, int mask) {
        if (u == n-1) return 0;
        if (dp[u][mask] != -1) return dp[u][mask];

        dp[u][mask] = -0x3f3f3f3f;
        for (pii i : adj[u]) {
                if (!(mask&1<<i.first)) {
                        dp[u][mask] = max(dp[u][mask], i.second + solve(i.first, mask|1<<i.first));
                }
        }

        return dp[u][mask];
}

int main() {
        cin.sync_with_stdio(0);
        cin.tie(0);
        memset(dp, -1, sizeof(dp));
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
                int s, d, l;
                cin >> s >> d >> l;
                adj[s].push_back({d, l});
        }

        cout << solve(0, 1) << '\n';
}