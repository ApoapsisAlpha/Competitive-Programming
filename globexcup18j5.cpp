#include <bits/stdc++.h>

using namespace std;

int n, m, q, c;
vector<int> adj[100001];
bool visited[100001];
int dist[100001];

int main() {
    scanf("%d %d %d %d", &n, &m, &q, &c);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    dist[c] = 0;
    queue<int> qu;
    visited[c] = true;
    qu.push(c);
    
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        for (int i : adj[u]) {
            if (!visited[i]) {
                dist[i] = dist[u] + 1;
                visited[i] = true;
                qu.push(i);
            }
        }
    }
    
    for (int i = 0; i < q; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (dist[a] == 0x3f3f3f3f || dist[b] == 0x3f3f3f3f) printf("This is a scam!\n");
        else printf("%d\n", dist[a]+dist[b]);
    }
    
    
}