#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
vector<pii> adj[100002];
int dist[100002];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }

    for (int i = 0; i <= n; i++) dist[i] = 0x3f3f3f3f;

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    dist[1] = 0;
    pq.push({dist[1], 1});
    
    while(!pq.empty()) {
        int d = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        if (d > dist[cur]) continue;

        for (pii i : adj[cur]) {
            if (dist[i.first] > dist[cur] + i.second) {
                dist[i.first] = dist[cur] + i.second;
                pq.push({dist[i.first], i.first});
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        printf("%d\n", dist[i] == 0x3f3f3f3f ? -1 : dist[i]);
    }
}