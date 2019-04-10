#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int> adj[28];
vector<pii> edges;
bool vis[28];
bool dfs(int u, pii block) {
    vis[u] = true;
    if (u == 1) return true;
    for (int i : adj[u]) {
        if (vis[i]) continue;
        if (block.first == u && block.second == i) continue;
        if (block.first == i && block.second == u) continue;
        if (dfs(i, block)) return true;
    }

    return false;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;
    while (s != "**") {
        int x = s[0]-'A';
        int y = s[1]-'A';
        adj[x].push_back(y);
        adj[y].push_back(x);
        edges.push_back({x, y});
        cin >> s;
    }

    int c = 0;
    for (pii e : edges) {
        memset(vis, false, sizeof(vis));
        if (!dfs(0, e)) {
            cout << (char)(e.first+'A') << (char)(e.second+'A') << '\n';
            c++;
        }
    }

    cout << "There are " << c << " disconnecting roads.";
}