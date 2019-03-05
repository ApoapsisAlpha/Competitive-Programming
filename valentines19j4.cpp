#include <bits/stdc++.h>
using namespace std;

int n, q, ans;
int m[301], p[301];
bool adj[301][301];

int main() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> m[i] >> p[i];
    }
    for (int i = 1; i <= q; i++) {
        int a, b;
        cin >> a >> b;
        adj[a][b] = true;
        adj[b][a] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (adj[i][j] || adj[i][k] || adj[j][k]) continue;
                int val = p[i];
                if (i != j) val = val*m[j]+p[j];
                if (i != k && j != k) val = val*m[k]+p[k];
                ans = max(ans, val);
            }
        }
    }

    cout << ans << '\n';
}