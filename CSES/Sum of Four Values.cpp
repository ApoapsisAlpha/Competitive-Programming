
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n, x;
pii a[1005];
vector<pair<int, pii>> v;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    if (n < 4) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        a[i] = make_pair(v, i+1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            v.push_back({a[i].first+a[j].first, {a[i].second, a[j].second}});
        }
    }

    sort(a, a+n);
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        if (i && v[i].first == v[i-1].first) continue;
        if (v[i].first > x-2) break;
        int l = 0, r = n-1;
        int i1 = v[i].second.first, i2 = v[i].second.second;
        int s = v[i].first;
        while (l < r) {
            while (a[l].second == i1 || a[l].second == i2) l++;
            while (a[r].second == i1 || a[r].second == i2) r--;
            if (a[l].first + a[r].first + s == x) {
                cout << i1 << " " << i2 << " " << a[l].second << " " << a[r].second << "\n";
                return 0;
            }
            else if (a[l].first + a[r].first + s < x) l++;
            else r--;
        }
    }

    cout << "IMPOSSIBLE\n";
}
