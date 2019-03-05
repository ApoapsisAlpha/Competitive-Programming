#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const ll INF = 0x3f3f3f3f3f3f3f3f;
char lvl[500001];
int par[500001], sz[500001];
ll dist[500001][20], ans[500001];
bool done[500001];
vector<pii> adj[500001];

void dfs(int u, int p) {
    sz[u] = 1;
    for (pii v : adj[u]) {
        if (v.first != p && !done[v.first]) {
            dfs(v.first, u);
            sz[u] += sz[v.first];
        }
    }
}

void dfs2(int u, int p, int curlvl, ll d) {
    dist[u][curlvl] = d;
    for (pii v : adj[u]) {
        if (v.first != p && !done[v.first]) {
            dfs2(v.first, u, curlvl, d + v.second);
        }
    }
}

int centre(int u, int p, int tot) {
    for (pii v : adj[u]) {
        if (v.first != p && !done[v.first] && sz[v.first]<<1 > tot) {
            return centre(v.first, u, tot);
        }
    }

    return u;
}

void decomp(int i, int p, int curlvl) {
    dfs(i, -1);
    int c = centre(i, -1, sz[i]);
    dfs2(c, -1, curlvl, 0);
    done[c] = true;
    lvl[c] = curlvl;
    par[c] = p;

    for (pii v : adj[c]) {
        if (v.first != p && !done[v.first]) {
             decomp(v.first, c, curlvl+1);
        }
    }
}

void Init(int N, int A[], int B[], int D[]) {
    for (int i = 0; i < N-1; i++) {
        adj[A[i]].push_back({B[i], D[i]});
        adj[B[i]].push_back({A[i], D[i]});
    }

    for (int i = 0; i < 500000; i++)
        ans[i] = INF;
    decomp(0, -1, 0);
}

long long Query(int S, int X[], int T, int Y[]) {
    ll mn = INF;
    for (int i = 0; i < S; i++) {
        int cur = X[i];
        while(cur != -1) {
            ans[cur] = min(ans[cur], dist[X[i]][lvl[cur]]);
            cur = par[cur];
        }
    }

    for (int i = 0; i < T; i++) {
        int cur = Y[i];
        while(cur != -1) {
            mn = min(mn, dist[Y[i]][lvl[cur]] + ans[cur]);
            cur = par[cur];
        }
    }

    for (int i = 0; i < S; i++) {
        int cur = X[i];
        while(cur != -1) {
            ans[cur] = INF;
            cur = par[cur];
        }
    }

    return mn;
}