#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[10001];
int dist[10001];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int m;
        scanf("%d", &m);
        for (int j = 0; j < m; j++) {
            int x;
            scanf("%d", &x);
            adj[i].push_back(x);
        }
    }

    memset(dist, 0x3f3f3f3f, sizeof(dist));
    dist[1] = 1;
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i : adj[u]) {
            if (dist[i] == 0x3f3f3f3f) {
                dist[i] = dist[u] + 1;
                q.push(i);
            }
        }
    }

    int mn = 0x3f3f3f3f;
    bool b = true;;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == 0x3f3f3f3f) b = false;
        if (adj[i].size() == 0) {
            mn = min(mn, dist[i]);
        }
    }

    if (b) printf("Y\n");
    else printf("N\n");
    printf("%d\n", mn);
}