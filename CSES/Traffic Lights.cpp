#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n, x;
set<int> s;
multiset<int> m;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> n;
    s.insert(0);
    s.insert(x);
    m.insert(x);
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        auto l = s.upper_bound(p);
        auto r = l--;
        if (p != x) {
            m.erase(m.find(*r-*l));
            m.insert(*r - p);
            m.insert(p - *l);
            s.insert(p);
        }
        cout << *--m.end() << " ";
    }
}
