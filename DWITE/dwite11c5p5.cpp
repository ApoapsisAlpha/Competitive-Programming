#include <bits/stdc++.h>

using namespace std;

int n, m, tot;
int grid[21][21];
bool filled[21][21];

void bfs(int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m) return;
    if (filled[r][c]) return;
    filled[r][c] = true;
    bfs(r, c-1);
    bfs(r, c+1);
    bfs(r-1, c);
    bfs(r+1, c);
}

int main() {
    for (int i = 0; i < 5; i++) {
        tot = 0;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d",  &grid[i][j]);
            }
        }

        for (int i = 0; i < 50; i++) {
            for (int r = 0; r < n; r++) {
                for (int c = 0; c < m; c++) {
                    filled[r][c] = grid[r][c] > i;
                }
            }

            for (int r = 0; r < n; r++) {
                for (int c = 0; c < m; c++) {
                    if (r == 0 || c == 0 || r == n-1 || c == m-1) {
                        bfs(r, c);
                    }
                }
            }

            for (int r = 0; r < n; r++) {
                for (int c = 0; c < m; c++) {
                    if (!filled[r][c]) {
                        tot++;
                    }
                }
            }
        }

        printf("%d\n", tot);
    }
}