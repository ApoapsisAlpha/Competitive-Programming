#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
vector<int> adj[100005];
bool vis[100005];
int dist[100005];
int pre[100005];

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

    queue<int> q;
    q.push(1);
    vis[1] = true;
    dist[1] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == n) break;
        for (int i : adj[u]) {
            if (vis[i]) continue;
            vis[i] = true;
            dist[i] = dist[u] + 1;
            pre[i] = u;
            q.push(i);
        }
    }

    vector<int> path;
    int cur = n;
    while (cur) {
        path.push_back(cur);
        cur = pre[cur];
    }

    if (dist[n] == 0) cout << "IMPOSSIBLE\n";
    else cout << dist[n] << "\n";
    for (int i = dist[n]-1; i >= 0; i--) {
        cout << path[i] << " ";
    }
}
