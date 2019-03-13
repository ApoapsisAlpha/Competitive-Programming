#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int k, sz[200001], mn[1000001], reset[1000001], curlvl, ans;
bool vis[200001];
vector<pii> adj[200001];

void calcsz(int u, int p) {
    sz[u] = 1;
    for (pii i : adj[u]) {
        if (i.first^p && !vis[i.first]) {
            calcsz(i.first, u);
            sz[u] += sz[i.first];
        }
    }
}

void dfs(int u, int p, int d, int lvl) {
    if (d > k) return;
    if (reset[k-d] == curlvl || k == d) {
        ans = min(ans, lvl+mn[k-d]);
    }

    for (pii i : adj[u]) {
        if (i.first^p && !vis[i.first]) {
            dfs(i.first, u, d + i.second, lvl+1);
        }
    }
}

void dfs2(int u, int p, int d, int lvl) {
    if (d > k) return;
    if (reset[d] != curlvl) {
        reset[d] = curlvl;
        mn[d] = lvl;
    }
    else {
        mn[d] = min(mn[d], lvl);
    }

    for (pii i : adj[u]) {
        if (i.first^p && !vis[i.first]) {
            dfs2(i.first, u, d + i.second, lvl+1);
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

void solve(int u) {
    calcsz(u, u);
    int c = centroid(u, u, sz[u]);
    curlvl++;

    for (pii i : adj[c]) {
        if (!vis[i.first]) {
            dfs(i.first, c, i.second, 1);
            dfs2(i.first, c, i.second, 1);
        }
    }

    vis[c] = true;
    for (pii i : adj[c]) {
        if (!vis[i.first]) {
            solve(i.first);
        }
    }
}

int best_path(int N, int K, int H[][2], int L[]) {
    ans = 0x3f3f3f3f;
    k = K;
    for (int i = 0; i < N-1; i++) {
        int a = H[i][0];
        int b = H[i][1];
        int c = L[i];
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    solve(0);
    return ans == 0x3f3f3f3f ? -1 : ans;
}

/*
int main()
{
    int l[11] = {3, 4, 5, 4, 6, 3, 2, 5, 6, 7};
    int h[11][2] = {
        {0, 1},
        {0, 2},
        {2, 3},
        {3, 4},
        {4, 5},
        {0, 6},
        {6, 7},
        {6, 8},
        {8, 9},
        {8, 10}
    };
    cout << best_path(11, 12, h, l);
}
*/