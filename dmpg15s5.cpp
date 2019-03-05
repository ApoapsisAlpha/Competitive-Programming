#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
bool grid[10002][10002];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y, w, h;
        scanf("%d %d %d %d", &x, &y, &w, &h);
        grid[x][y] ^= 1;
        grid[x+w][y] ^= 1;
        grid[x][y+h] ^= 1;
        grid[x+w][y+h] ^= 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            grid[i][j] ^= grid[i][j-1];
        }
    }

    for (int i = 0; i < n; i++) ans += grid[0][i];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] ^= grid[i-1][j];
            ans += grid[i][j];
        }
    }

    printf("%d\n", ans);
}