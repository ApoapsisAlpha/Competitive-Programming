#include <bits/stdc++.h>
using namespace std;

int n, m, k;
pair<int, int> t[100001];
long long d, ans;

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &t[i].second, &t[i].first);
        d += k-t[i].second;
    }

    sort(t, t+n);

    for (int i = 0; i < n; i++) {
        if (d <= 0) break;
        long long x = m-t[i].second;
        if (d-x < 0) {
            ans += d*t[i].first;
            d = 0;
        }
        else {
            d -= x;
            ans += x*t[i].first;
        }
    }

    printf("%lld", ans);
}