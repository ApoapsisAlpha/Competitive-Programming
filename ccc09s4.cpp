#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int n, t, k, d, ans;
vector<pii> adj[5001];
pii p[5001];
int dist[5001];

int main() {
    scanf("%d", &n);
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        adj[x].push_back({y, c});
        adj[y].push_back({x, c});
    }

    scanf("%d", &k);
    for (int i = 0; i < k; i++) {
        scanf("%d %d", &p[i].first, &p[i].second);
    }

    scanf("%d", &d);

    memset(dist, 0x3f3f3f3f, sizeof(dist));
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[d] = 0;
    pq.push({dist[d], d});

    while (!pq.empty()) {
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

    ans = 0x3f3f3f3f;
    for (int i = 0; i < k; i++) {
        ans = min(ans, dist[p[i].first]+p[i].second);
    }

    printf("%d\n", ans);
}