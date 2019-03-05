#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, mxpath, dp[400001], cnt[400001];
ll numpaths;
vector<int> adj[400001];

void dfs(int u, int p) {
    cnt[u] = 1;
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u);
        if (dp[v]+dp[u]+1 > mxpath) {
            mxpath = dp[v]+dp[u]+1;
            numpaths = (ll)cnt[v]*cnt[u];
        }
        else if (dp[v]+dp[u]+1 == mxpath) {
            numpaths += (ll)cnt[v]*cnt[u];
        }

        if(dp[v]+1 > dp[u]) {
            cnt[u] = cnt[v];
            dp[u] = dp[v]+1;
        }
        else if(dp[v]+1 == dp[u]) {
            cnt[u] += cnt[v];
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n-1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, -1);
    printf("%d %lld\n", mxpath+1, numpaths);
}