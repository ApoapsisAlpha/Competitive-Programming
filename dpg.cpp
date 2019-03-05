#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, ans;
vector<int> adj[100001];
int edges[100001];
bool vis[100001];
int dis[100001];

void dfs(int u) {
    vis[u] = true;
    for (int i : adj[u]) {
        dis[i] = max(dis[i], dis[u]+1);
        edges[i]--;

        if (edges[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        adj[x].push_back(y);
        edges[y]++;
    }

    for (int i = 1; i <= n; i++) {
        if (!vis[i] && edges[i] == 0) {
            dfs(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        ans = max(ans, dis[i]);
    }

    printf("%d\n", ans);
}