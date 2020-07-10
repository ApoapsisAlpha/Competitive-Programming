#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n, m;
pii s, e;
bool vis[1005][1005];
int dist[1005][1005];
pii pre[1005][1005];
pii predir[1005][1005];
pii directions[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == 'A') s = make_pair(i, j);
            else if (c == 'B') e = make_pair(i, j);
            else if (c == '#') vis[i][j] = true;
        }
    }

    list<pii> q;
    q.push_back(s);
    pre[s.first][s.second] = make_pair(-1, -1);
    vis[s.first][s.second] = true;
    while (!q.empty()) {
        pii cur = q.front();
        q.pop_front();
        if (cur.first == e.first && cur.second == e.second) {
            cout << "YES\n";
            cout << dist[e.first][e.second] << "\n";
            string dirs = "";
            pii c = e;
            while (c.first != -1 || c.second != -1) {
                pii x = predir[c.first][c.second];
                if (x.first == 1 && x.second == 0) dirs += 'D';
                if (x.first == -1 && x.second == 0) dirs += 'U';
                if (x.first == 0 && x.second == 1) dirs += 'R';
                if (x.first == 0 && x.second == -1) dirs += 'L';
                c = pre[c.first][c.second];
            }
            reverse(dirs.begin(), dirs.end());
            cout << dirs << "\n";
            return 0;
        }

        for (pii dir : directions) {
            int newr = cur.first + dir.first;
            int newc = cur.second + dir.second;
            if (newr < 0 || newr >= n || newc < 0 || newc >= m || vis[newr][newc]) continue;
            dist[newr][newc] = dist[cur.first][cur.second] + 1;
            pre[newr][newc] = cur;
            predir[newr][newc] = dir;
            vis[newr][newc] = true;
            q.push_back(make_pair(newr, newc));
        }
    }

    cout << "NO\n";
}
