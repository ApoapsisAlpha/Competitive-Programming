#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

int n, m;
vector<pii> adj[100005];
ll dist[100005];
bool vis[100005][2];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    for (int i = 1; i <= n; i++) dist[i] = 1e18;
    priority_queue<pair<pli, bool>, vector<pair<pli, bool>>, greater<pair<pli, bool>>> pq;
    pq.push({{0, 1}, 0});
    dist[1] = 0;
    while (!pq.empty()) {
        int u = pq.top().first.second;
        bool b = pq.top().second;
        pq.pop();

        if (u == n) {
            cout << dist[n] << "\n";
            return 0;
        }

        if (vis[u]) continue;
        vis[u][b] = true;

        for (pii i : adj[u]) {
            if (dist[u] + i.second < dist[i.first]) {
                dist[i.first] = dist[u] + i.second;
                pq.push({{dist[i.first], i.first}, b});
            }

            if (!b && dist[u] + i.second/2 < dist[i.first]) {
                dist[i.first] = dist[u] + i.second/2;
                pq.push({{dist[i.first], i.first}, 1});
            }
        }
    }

    cout << "-1\n";
}
