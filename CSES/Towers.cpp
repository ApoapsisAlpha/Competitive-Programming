
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n;
multiset<int> s;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        auto it = s.upper_bound(x);
        if (it != s.end()) s.erase(it);
        s.insert(x);
    }

    cout << s.size() << "\n";
}

