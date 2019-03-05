#include <bits/stdc++.h>
using namespace std;

struct pipe {
    int i, a, b, c;
    bool operator<(const pipe& p) const {
        if (c == p.c) return i < p.i;
        return c < p.c;
    }
};

int n, m, d, ans, mx;
int p[100001], rk[100001];
vector<pipe> pipes;

int find(int x) {
    if (x != p[x]) return p[x] = find(p[x]);
    return p[x];
}

bool merge(int a, int b) {
    int r1 = find(a);
    int r2 = find(b);
    if(r1 == r2) return false;
    if (rk[r1] > rk[r2]) p[r2] = r1;
    else p[r1] = r2;
    if (rk[r1] == rk[r2]) rk[r2]++;
    return true;
}

int main() {
    scanf("%d %d %d", &n, &m, &d);
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 1; i <= m; i++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        pipes.push_back({i, x, y, z});
    }

    sort(pipes.begin(), pipes.end());
    for (int i = 0; i < m; i++) {
        if (merge(pipes[i].a, pipes[i].b)) {
            mx = pipes[i].c;
            if (pipes[i].i >= n) ans++;
        }
    }

    for (int i = 1; i <= n; i++) {
        p[i] = i;
        rk[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        if (find(pipes[i].a) != find(pipes[i].b)) {
            if (pipes[i].c < mx || (pipes[i].c == mx && pipes[i].i < n)) {
                merge(pipes[i].a, pipes[i].b);
            }
            else if (pipes[i].i < n && pipes[i].c <= d) {
                printf("%d\n", ans-1);
                return 0;
            }
        }
    }

    printf("%d\n", ans);
}