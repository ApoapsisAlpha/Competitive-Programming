#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int a, b, k, n, m;
vector<piii> adj[2002];
int dist[2002][202];

int main() {
    scanf("%d %d %d", &k, &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b, t, h;
        scanf("%d %d %d %d", &a, &b, &t, &h);
        adj[a].push_back({b, {t, h}});
        adj[b].push_back({a, {t, h}});
    }

    scanf("%d %d", &a, &b);

    priority_queue<piii, vector<piii>, greater<piii> > pq;
    memset(dist, 0x3f3f3f3f, sizeof(dist));
    dist[a][0] = 0;
    pq.push({0, {a, 0}});
    while (!pq.empty()) {
        piii u = pq.top();
        pq.pop();
        for (piii i : adj[u.second.first]) {
            int w = u.first+i.second.first;
            int h = u.second.second+i.second.second;
            if (h < k && w < dist[i.first][h]) {
                dist[i.first][h] = w;
                pq.push({w, {i.first, h}});
            }
        }
    }

    int mn = 0x3f3f3f3f;
    for (int i = 0; i <= 200; i++) {
        mn = min(mn, dist[b][i]);
    }

    if (mn == 0x3f3f3f3f) printf("-1\n");
    else printf("%d\n", mn);
}