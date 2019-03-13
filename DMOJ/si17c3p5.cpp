#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int n;
long long ans;
int sz[100001];
bool vis[100001];
vector<pii> adj[100001];
unordered_map<int, int> m;

void calcsz(int u, int p) {
    sz[u] = 1;
    for (pii i : adj[u]) {
        if (i.first^p && !vis[i.first]) {
            calcsz(i.first, u);
            sz[u] += sz[i.first];
        }
    }
}

int centroid(int u, int p, int tot) {
    for (pii i : adj[u]) {
        if (i.first^p && !vis[i.first] && 2*sz[i.first] > tot) {
            return centroid(i.first, u, tot);
        }
    }

    return u;
}

void dfs(int u, int p, int d, int lvl) {
    ans += m[-d+1];
    ans += m[-d-1];

    for (pii i : adj[u]) {
        if (i.first^p && !vis[i.first]) {
            dfs(i.first, u, d+i.second, lvl+1);
        }
    }
}

void dfs2(int u, int p, int d) {
    m[d]++;
    for (pii i : adj[u]) {
        if (i.first^p && !vis[i.first]) {
            dfs2(i.first, u, d+i.second);
        }
    }
}

void solve(int u) {
    calcsz(u, u);
    int c = centroid(u, u, sz[u]);
    vis[c] = true;
    m[0] = 1;

    for (pii i : adj[c]) {
        if (!vis[i.first]) {
            dfs(i.first, i.first, i.second, 1);
            dfs2(i.first, i.first, i.second);
        }
    }

    m.clear();
    for (pii i : adj[c]) {
        if (!vis[i.first]) {
            solve(i.first);
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b, v;
        char c;
        cin >> a >> b >> c;
        if (c == 'r') v = 1;
        else v = -1;
        adj[a].push_back({b, v});
        adj[b].push_back({a, v});
    }

    solve(1);
    cout << ans - n + 1;
}
