#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n, t;
int a[200005];
ll l, r;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        r = max(r, (ll)a[i]*t);
    }

    while (l < r) {
        ll m = l + (r-l)/2;
        ull c = 0;
        for (int i = 0; i < n; i++) c += m/a[i];
        if (c >= t) {
            r = m;
        }
        else {
            l = m+1;
        }
    }

    cout << l << "\n";
}
