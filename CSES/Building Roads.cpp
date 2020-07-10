#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
vector<int> adj[100005];
bool vis[100005];
vector<pii> ans;

void dfs(int u) {
    vis[u] = true;
    for (int i : adj[u]) {
        if (vis[i]) continue;
        dfs(i);
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int k = 0;
    int prev = 1;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            dfs(i);
            if (i != prev) {
                ans.push_back({prev, i});
                k++;
            }
            prev = i;
        }
    }

    cout << k << "\n";
    for (pii i : ans) cout << i.first << " " << i.second << "\n";
}
