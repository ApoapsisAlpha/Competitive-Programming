#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m, x, mxcount, tot;
bool pho[100001];
bool mark[100001];
vector<int> adj[100001];

void dfs(int u, int p) {
    if (pho[u]) {
        mark[u] = true;
        tot++;
    }
    
    for (int i : adj[u]) {
        if (i == p) continue;
        dfs(i, u);
        if (mark[i] && !mark[u]) {
            mark[u] = true;
            tot++;
        }
    }
}

void dfs2(int u, int p, int c) {
    c++;
    for (int i : adj[u]) {
        if (i != p && mark[i]) {
            if (c >= mxcount) {
                mxcount = c;
                x = i;
            }
            
            dfs2(i, u, c);
        }
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x;
        scanf("%d", &x);
        pho[x] = true;
    }

    for (int i = 0; i < n-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int i;
    for (i = 0; i < n; i++) {
        if (pho[i]) {
            dfs(i, -1);
            break;
        }
    }

    dfs2(i, -1, 0);
    dfs2(x, -1, 0);

    printf("%d\n", 2*tot-mxcount-2);
}