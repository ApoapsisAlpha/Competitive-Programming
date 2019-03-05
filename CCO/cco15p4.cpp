#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[2001][2001];

void dfs(int i, int j) {
    if (grid[i][j] == 'N') {
        for (int k = i-1; k >= 0; k--) {
            if (grid[k][j] == '.') continue;
            dfs(k, j);
        }
    }
    else if (grid[i][j] == 'S') {
        for (int k = i+1; k < n; k++) {
            if (grid[k][j] == '.') continue;
            dfs(k, j);
        }
    }
    else if (grid[i][j] == 'W') {
        for (int k = j-1; k >= 0; k--) {
            if (grid[i][k] == '.') continue;
            dfs(i, k);
        }
    }
    else if (grid[i][j] == 'E') {
        for (int k = j+1; k < m; k++) {
            if (grid[i][k] == '.') continue;
            dfs(i, k);
        }
    }
    
    grid[i][j] = '.';
    printf("(%d,%d)\n", i, j);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", grid[i]);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != '.') {
                dfs(i, j);
            }
        }
    }
}