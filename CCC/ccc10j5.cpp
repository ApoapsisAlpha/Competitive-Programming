#include <bits/stdc++.h>

using namespace std;

struct Node {
    int r, c;
};

int moves[8][2] = {{1, 2}, {-1, 2}, {1, -2}, {-1, -2}, {2, 1}, {-2, 1}, {2, -1}, {-2, -1}};
int r1, c1, r2, c2;
bool visited[9][9];
list<Node> q;
int dist[9][9];

int main() {
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);

    if (r1 == r2 && c1 == c2) {
        printf("0\n");
        return 0;
    }

    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            dist[i][j] = 0x3f3f3f3f;
        }
    }

    visited[r1][c1] = true;
    Node n;
    n.r = r1;
    n.c = c1;
    dist[r1][c1] = 0;
    q.push_back(n);

    while(!q.empty()) {
        Node u = q.front();
        q.pop_front();
        for (int i = 0; i < 8; i++) {
            int r = u.r + moves[i][0];
            int c = u.c + moves[i][1];
            if (0 < r && r <= 8 && 0 < c & c <= 8 && !visited[r][c]) {
                visited[r][c] = true;
                dist[r][c] = dist[u.r][u.c] + 1;
                Node k;
                k.r = r;
                k.c = c;
                q.push_back(k);

                if (r == r2 && c == c2) {
                    printf("%d\n", dist[r][c]);
                    return 0;
                }
            }
        }
    }
}