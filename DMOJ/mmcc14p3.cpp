#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, s;
vector<int> adj[5001];
int par[5001], lvl[5001];
vector<pii> a;
bool vis[5001];

void dfs(int u, int d) {
    lvl[u] = d;
    for (int i : adj[u]) {
        if (i^par[u]) {
            par[i] = u;
            dfs(i, d+1);
        }
    }
}

void mark(int u, int p, int d) {
    vis[u] = true;
    if (d == 0) return;
    for (int i : adj[u]) {
        if (i^p) {
            mark(i, u, d-1);
        }
    }
}

bool check(int d) {
    memset(vis, false, sizeof(vis));
    int tot = 0;
    for (pii i : a) {
        if (!vis[i.second]) {
            int cur = i.second;
            for (int i = 0; i < d && cur != 1; i++) {
                cur = par[cur];
            }
            mark(cur, -1, d);
            tot++;
        }
    }

    return tot <= s;
}

int main() {
    scanf("%d %d", &n, &s);
    for (int i = 0, x, y; i < n-1; i++) {
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        a.push_back({lvl[i], i});
    }

    sort(a.begin(), a.end(), greater<pii>());

    int low = 0;
    int high = 5000;
    while (low < high) {
        int mid = (low+high)>>1;
        if (check(mid)) high = mid;
        else low = mid + 1;
    }

    printf("%d\n", low);
}