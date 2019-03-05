#include <bits/stdc++.h>

using namespace std;

int n, m, k, a, b;
vector<int> adj[100001];
set<int> buildings;
map<int, int> a1, a2;

void bfs() {
    list<int> nqueue;
    int dist[n+1];
    bool visited[n+1];
    
    for (int i = 0; i <= n; i++) {
        visited[i] = false;
        dist[i] = 0x3f3f3f3f;
    }

    dist[a] = 0;
    visited[a] = true;

    nqueue.push_back(a);

    while (!nqueue.empty()) {
        int u = nqueue.front();
        nqueue.pop_front();
        for (int i = 0; i < adj[u].size(); i++) {
            if (!visited[adj[u][i]]) {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                nqueue.push_back(adj[u][i]);

                if (buildings.count(adj[u][i])) {
                    a1[adj[u][i]] = dist[adj[u][i]];
                }
            }
        }
    }
}

void bfs2() {
    list<int> nqueue;
    int dist[n+1];
    bool visited[n+1];
    
    for (int i = 0; i <= n; i++) {
        visited[i] = false;
        dist[i] = 0x3f3f3f3f;
    }

    dist[b] = 0;
    visited[b] = true;

    nqueue.push_back(b);

    while (!nqueue.empty()) {
        int u = nqueue.front();
        nqueue.pop_front();
        for (int i = 0; i < adj[u].size(); i++) {
            if (!visited[adj[u][i]] || adj[u][i] == b) {
                visited[adj[u][i]] = true;
                dist[adj[u][i]] = dist[u] + 1;
                nqueue.push_back(adj[u][i]);

                if (buildings.count(adj[u][i])) {
                    a2[adj[u][i]] = dist[adj[u][i]];
                }
            }
        }
    }
    
}

int main() {
    scanf("%d %d %d %d %d", &n, &m, &k, &a, &b);

    for (int i = 0; i < k; i++) {
        int x;
        scanf("%d", &x);
        buildings.insert(x);
    }

    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    bfs();
    bfs2();

    int mindist = 0x3f3f3f3f;

    for (int i : buildings) {
        mindist = min(mindist, a1[i] + a2[i]);
    }

    printf("%d", mindist);
    
}