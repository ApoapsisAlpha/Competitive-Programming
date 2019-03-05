#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1001];
int n, m, a, b;

int bfs(int x, int y) {
    if (x == y) return 0;

    list<int> queue;
    bool visited[n];
    int dist[n];

    for (int i = 0; i < n; i++) {
        visited[i] = false;
        dist[i] = 0x3f3f3f3f;
    }
  
    visited[x] = true;
    dist[x] = 0;
    queue.push_back(x);

    while (!queue.empty()) {
        int u = queue.front();
        queue.pop_front();
        for (int i = 0; i < adj[u].size(); i++) {
            if (visited[adj[u][i]] == false) {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                queue.push_back(adj[u][i]);

                if (adj[u][i] == y)
                   return dist[y];
            }
        }
    }

    return -1;
}

int main() {
    scanf("%d %d %d %d", &n, &m, &a, &b);

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int ans = bfs(1, a) + bfs(a, b);
    if (ans < 0) printf("-1");
    else printf("%d", ans);

}