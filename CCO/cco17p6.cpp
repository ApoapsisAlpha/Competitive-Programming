#include <bits/stdc++.h>
using namespace std;

struct Point {
    int r, c;
};

struct Move {
    int a, b, c;
};

int n, m, c;
Point loc[10001];
int grid[101][101];
vector<Move> moves;

void shiftRight(int x, int k) {
    c++;
    moves.push_back({1, x+1, k});
    int row[101];
    for (int i = 0; i < m; i++) {
        int j = grid[x][i];
        loc[j].c = (loc[j].c+k)%m;
        row[loc[j].c] = j; 
    }
    
    for (int i = 0; i < m; i++) {
        grid[x][i] = row[i];
    }
}

void shiftDown(int x, int k) {
    c++;
    moves.push_back({2, x+1, k});
    int col[101];
    for (int i = 0; i < n; i++) {
        int j = grid[i][x];
        loc[j].r = (loc[j].r+k)%n;
        col[loc[j].r] = j;
    }
    
    for (int i = 0; i < n; i++) {
        grid[i][x] = col[i];
    }
}

void shiftLeft(int x, int k) {
    shiftRight(x, m-k);
}

void shiftUp(int x, int k) {
    shiftDown(x, n-k);
}

void swap(int i, int j) {
    shiftLeft(n-1, i);
    shiftDown(0, 1);
    shiftLeft(n-1, j-i);
    shiftUp(0, 1);
    shiftRight(n-1, j-i);
    shiftDown(0, 1);
    shiftRight(n-1, i);
}

void ins(int x) {
    int row = x/m;
    int col = x%m;
    Point cur = loc[x];
    if (cur.r == row && cur.c == col) return;
    if (cur.r == row) {
        shiftLeft(row, cur.c-col);
        shiftUp(col, 1);
        shiftRight(row, cur.c-col);
        shiftDown(col, 1);
    }
    else if (cur.c == col) {
        shiftRight(cur.r, 1);
        shiftDown(col, cur.r-row);
        shiftLeft(cur.r, 1);
        shiftUp(col, cur.r-row);
    }
    else if (cur.c > col) {
        shiftDown(col, cur.r-row);
        shiftLeft(cur.r, cur.c-col);
        shiftUp(col, cur.r-row);
    }
    else {
        shiftDown(col, cur.r-row);
        shiftRight(cur.r, col-cur.c);
        shiftUp(col, cur.r-row);
    }
}

void pll() {
    shiftLeft(n-1, loc[m*(n-1)].c);
    for (int i = m*(n-1)+1; i < n*m; i++) {
        int col = i%m;
        Point cur = loc[i];
        if (cur.c == col && cur.r == n-1) continue;
        if (cur.r < n-1) {
            if (col == m-1) {
                shiftRight(n-1, 1);
                shiftDown(0, 1);
                shiftLeft(n-1, 1);
                while(grid[0][0]) swap(0, 1);
                continue;
            }
            shiftLeft(n-1, col);
            shiftDown(0, 1);
            shiftLeft(n-1, 1);
            shiftUp(0, 1);
            shiftRight(n-1, col+1);
            
        }
        else {
            shiftLeft(n-1, cur.c);
            shiftDown(0, 1);
            shiftRight(n-1, cur.c-col);
            shiftUp(0, 1);
            shiftRight(n-1, col);
        }
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &grid[i][j]);
            loc[grid[i][j]] = {i, j};
        }
    }
    
    for (int i = 0; i < (n-1)*m; i++) {
        ins(i);
    }
    
    pll();
    printf("%d\n", c);
    for (int i = 0; i < c; i++) {
        printf("%d %d %d\n", moves[i].a, moves[i].b, moves[i].c);
    }
}