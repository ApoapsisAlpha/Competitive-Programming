#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, m, c;
int p[200001], rk[200001];

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
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) p[i] = i;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (!merge(a, b)) {
            c++;
        }
    }

    if (c <= 1) cout << "YES\n";
    else cout << "NO\n";
}
