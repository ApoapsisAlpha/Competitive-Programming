#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
vector<int> adj[100005];
bool vis[100005];
bool team[100005];

bool dfs(int u, bool t) {
    vis[u] = true;
    team[u] = t;
    for (int i : adj[u]) {
        if (vis[i]) {
            if (team[i] == t) return false;
        }
        else if (!dfs(i, !t)) return false;
    }

    return true;
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

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            if (!dfs(i, 0)) {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << (team[i]+1) << " ";
    }
}

