#include <bits/stdc++.h>
using namespace std;

int n, m;
int p[100001], rk[100001];
vector<int> res;

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
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (merge(x, y)) {
            res.push_back(i);
        }
    }

    if (res.size() == n-1) {
        for (int i : res) printf("%d\n", i);
    }
    else printf("Disconnected Graph");
}