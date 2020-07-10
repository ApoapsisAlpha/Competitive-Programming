#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 1e9+5;
int n, m;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
string dn = "UDLR";
char g[1005][1005];
int dist[1005][1005];
int steps[1005][1005];
int dir[1005][1005];
pii start;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    queue<pii> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
            dist[i][j] = INF;
            steps[i][j] = -1;
            if (g[i][j] == 'M') {
                q.push({i, j});
                dist[i][j] = 0;
            }
            else if (g[i][j] == 'A') start = {i, j};
        }
    }

    while (!q.empty()) {
        pii u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int newr = u.first + dr[i];
            int newc = u.second + dc[i];
            if (newr < 0 || newr >= n || newc < 0 || newc >= m) continue;
            if (g[newr][newc] == '#' || dist[newr][newc] != INF) continue;
            dist[newr][newc] = dist[u.first][u.second] + 1;
            q.push({newr, newc});
        }
    }

    q.push(start);
    steps[start.first][start.second] = 0;
    while (!q.empty()) {
        pii u = q.front();
        q.pop();
        if (u.first == 0 || u.first == n-1 || u.second == 0 || u.second == m-1) {
            string ans = "";
            int i = dir[u.first][u.second];
            while (u.first != start.first || u.second != start.second) {
                ans += dn[i];
                u.first -= dr[i];
                u.second -= dc[i];
                i = dir[u.first][u.second];
            }
            reverse(ans.begin(), ans.end());
            cout << "YES\n";
            cout << (int)ans.size() << "\n";
            cout << ans << "\n";
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int newr = u.first + dr[i];
            int newc = u.second + dc[i];
            if (newr < 0 || newr >= n || newc < 0 || newc >= m) continue;
            if (g[newr][newc] == '#' || steps[newr][newc] != -1) continue;
            if (dist[newr][newc] < steps[u.first][u.second] + 1) continue;
            steps[newr][newc] = steps[u.first][u.second] + 1;
            dir[newr][newc] = i;
            q.push({newr, newc});
        }
    }

    cout << "NO\n";
}
