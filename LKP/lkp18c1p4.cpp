#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, int> plli;

int n, m;
ll c;
vector<piii> adj[100005];
ll dist[100005];

bool check(int a, int b, int p) {
    for (int i = 0; i < 100005; i++) {
        dist[i] = 200000000000;
    }
    priority_queue<plli, vector<plli>, greater<plli>> pq;
    dist[a] = 0;
    pq.push({0, a});

    while (!pq.empty()) {
        int d = pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        if (dist[cur] > c || d > dist[cur]) continue;

        for (auto i : adj[cur]) {
            if (i.first > p) continue;
            if (dist[i.second.first] > dist[cur] + i.second.second) {
                dist[i.second.first] = dist[cur] + i.second.second;
                pq.push({dist[i.second.first], i.second.first});
            }
        }
    }

    if (dist[b] <= c) return true;
    return false;
}

int main() {
    scanf("%d %d", &n, &m);

    int a, b;
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %lld", &a, &b, &c);
        adj[a].push_back({i, {b, c}});
        adj[b].push_back({i, {a, c}});
    }

    scanf("%d %d %lld", &a, &b, &c);

    int low = 1;
    int high = m;

    while (low < high) {
        int mid = (low+high)/2;
        if (check(a, b, mid)) high = mid;
        else low = mid+1;
    }

    if ((low == 1 || low == m)  && !check(a, b, low)) printf("-1\n");
    else printf("%d\n", low);
}