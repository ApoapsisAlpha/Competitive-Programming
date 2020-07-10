#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n, k;
int a[200005];
ll l, r;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        r += a[i];
        l = max(l, (ll)a[i]);
    }

    while (l < r) {
        ll m = l + (r-l)/2;
        ll sum = 0;
        int c = 1;
        for (int i = 0; i < n; i++) {
            if (sum + a[i] > m) {
                sum = 0;
                c++;
            }
            sum += a[i];
        }

        if (c <= k) r = m;
        else l = m + 1;
    }

    cout << l << "\n";
}
