#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int ans;
string s;
bool vis[10][10];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void solve(int i, int r, int c, int d) {
    if (r == 6 && c == 0) {
        if (i == 48) ans++;
        return;
    }

    if (d == 0 && (r == 0 || vis[r-1][c]) && c > 0 && c < 6 && !vis[r][c-1] && !vis[r][c+1]) return;
    if (d == 1 && (r == 6 || vis[r+1][c]) && c > 0 && c < 6 && !vis[r][c-1] && !vis[r][c+1]) return;
    if (d == 2 && (c == 0 || vis[r][c-1]) && r > 0 && r < 6 && !vis[r-1][c] && !vis[r+1][c]) return;
    if (d == 3 && (c == 6 || vis[r][c+1]) && r > 0 && r < 6 && !vis[r-1][c] && !vis[r+1][c]) return;

    if (s[i] == '?') {
        for (int j = 0; j < 4; j++) {
            int new_r = r + dr[j];
            int new_c = c + dc[j];
            if (vis[new_r][new_c] || new_r < 0 || new_r > 6 || new_c < 0 || new_c > 6) continue;
            vis[new_r][new_c] = true;
            solve(i+1, new_r, new_c, j);
            vis[new_r][new_c] = false;
        }
    }
    else {
        int j = 0;
        if (s[i] == 'U') j = 0;
        else if (s[i] == 'D') j = 1;
        else if (s[i] == 'L') j = 2;
        else if (s[i] == 'R') j = 3;
        int new_r = r + dr[j];
        int new_c = c + dc[j];
        if (vis[new_r][new_c] || new_r < 0 || new_r > 6 || new_c < 0 || new_c > 6) return;
        vis[new_r][new_c] = true;
        solve(i+1, new_r, new_c, j);
        vis[new_r][new_c] = false;
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    vis[0][0] = true;
    solve(0, 0, 0, 0);

    cout << ans << "\n";
}

