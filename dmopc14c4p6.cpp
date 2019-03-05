#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[500001];
int ins[500001], out[500001];

void dfs1(int u, int p) {
    for (int v : adj[u]) {
        if (v == p) continue;
        dfs1(v, u);
        ins[u] = max(ins[u], 1+ins[v]);
    }
}

void dfs2(int u, int p) {
    int mx1(-1), mx2(-1);
    for (int v : adj[u]) {
        if (v == p) continue;
        if (ins[v] >= mx1) mx2 = mx1, mx1 = ins[v];
        else if (ins[v] > mx2) mx2 = ins[v];
    }
    
    for (int v : adj[u]) {
        if (v == p) continue;
        int mx = mx1;
        if (mx1 == ins[v]) mx = mx2;
        out[v] = 1+max(out[u], mx+1);
        dfs2(v, u);
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

    dfs1(1, -1);
    dfs2(1, -1);
    for (int i = 1; i <= n; i++) {
        printf("%d\n", 1+max(ins[i], out[i]));
    }
}