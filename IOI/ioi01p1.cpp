#include <bits/stdc++.h>
using namespace std;

int n, s;
int tree[1026][1026];

void update(int x, int y, int v) {
    int y1;
    while (x <= s) {
        y1 = y;
        while (y1 <= s) {
            tree[x][y1] += v;
            y1 += (y1 & -y1);
        }
        x += (x & -x);
    }
}

int query(int x, int y) {
    int sum = 0;
    int y1;
    while (x > 0) {
        y1 = y;
        while (y1 > 0) {
            sum += tree[x][y1];
            y1 -= (y1 & -y1);
        }
        x -= (x & -x);
    }

    return sum;
}

int main() {
    for (int i = 0; i < 1025; i++) {
        for (int j = 0; j < 1025; j++) {
            tree[i][j] = 0;
        }
    }

    scanf("%d", &n);
    while (n != 3) {
        switch(n) {
            case 0:
                scanf("%d", &s);
                break;
            case 1:
                int x, y, v;
                scanf("%d %d %d", &x, &y, &v);
                update(x+1, y+1, v);
                break;
            case 2:
                int x1, y1, x2, y2;
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                x1++; y1++; x2++; y2++;
                printf("%d\n", query(x2, y2)-query(x1-1, y2)-query(x2, y1-1)+query(x1-1, y1-1));
                break;
        }
        scanf("%d", &n);
    }
}