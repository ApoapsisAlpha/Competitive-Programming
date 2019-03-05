#include <bits/stdc++.h>

using namespace std;

pair<int, int> a[5001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    long long res = 0;
    cin >> n >> x;
    
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    
    int s, e;
    s = e = x;
    for (int i = 1; i <= n; i++) {
        if (s > a[i].second) {
            res += s - a[i].second;
            e = s;
            s = a[i].second;
        }
        else if (e < a[i].first) {
            res += a[i].first - e;
            s = e;
            e = a[i].first;
        }
        else {
            s = max(s, a[i].first);
            e = min(e, a[i].second);
        }
    }

    cout << res;
}