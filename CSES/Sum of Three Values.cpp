
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n, x;
pii a[5005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        a[i] = make_pair(v, i+1);
    }

    sort(a, a+n);
    for (int i = 0; i < n; i++) {
        if (a[i].first >= x) break;
        int l = 0, r = n-1;
        while (l < r) {
            if (l == i) l++;
            if (r == i) r--;
            if (a[l].first + a[r].first + a[i].first == x) {
                cout << a[i].second << " " << a[l].second << " " << a[r].second << "\n";
                return 0;
            }
            else if (a[l].first + a[r].first + a[i].first < x) l++;
            else r--;
        }
    }

    cout << "IMPOSSIBLE\n";
}
