#include <bits/stdc++.h>
using namespace std;

int n, q, m;
int a[50001][10];
bool vis[10];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q >> m;
    m *= 10;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        string s = to_string(x);
        for (int j = 0; j < 10; j++) vis[j] = false;
        for (int j = 0; j < s.size(); j++) {
            vis[s[j]-'0'] = true;
        }
        for (int j = 0; j < 10; j++) {
            if (vis[j]) {
                a[x%m][j] += x;
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int k, t;
        cin >> k >> t;
        cout << a[k][t] << '\n';
    }
}
