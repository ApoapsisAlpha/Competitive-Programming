#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
vector<int> adj[100005];
bool vis[100005];
stack<int> s;

bool dfs(int u, int p) {
    vis[u] = true;
    s.push(u);
    for (int i : adj[u]) {
        if (i^p) {
            if (vis[i]) {
                s.push(i);
                return true;
            }
            else {
                if (dfs(i, u)) return true;
            }
        }
    }

    s.pop();
    return false;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool possible = false;
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && dfs(i, 0)) {
            possible = true;
            break;
        }
    }
    if (possible) {
        vector<int> a;
        int t = s.top();
        a.push_back(t);
        s.pop();
        while (!s.empty() && s.top() != t) {
            a.push_back(s.top());
            s.pop();
        }

        a.push_back(t);

        cout << (int)a.size() << "\n";
        for (int i : a) cout << i << " ";
    }
    else cout << "IMPOSSIBLE\n";
}
