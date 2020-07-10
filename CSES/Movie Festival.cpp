#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n, ans;
pii a[200005];

bool cmp(pii a, pii b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = make_pair(x, y);
    }

    sort(a, a+n, cmp);

    int prev = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].first >= prev) {
            ans++;
            prev = a[i].second;
        }
    }

    cout << ans << "\n";
}
