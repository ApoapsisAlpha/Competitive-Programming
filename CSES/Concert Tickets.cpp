#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n, m;
multiset<int, greater<int>> h;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        h.insert(x);
    }

    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        auto p = h.lower_bound(t);
        if (p == h.end()) cout << "-1\n";
        else {
            cout << *p << '\n';
            h.erase(p);
        }
    }
}
