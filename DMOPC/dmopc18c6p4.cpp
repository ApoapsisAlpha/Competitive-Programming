#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n, p, m, ans;
ll best;
pii u[200001];
int a[200001];
int b[200001];
ll psa1[200001];
ll psa2[200001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> p >> m;
    for (int i = 0; i < n; i++) {
        cin >> u[i].first >> u[i].second;
    }
    for (int i = 1; i <= p; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

    sort(a+1, a+p+1);
    sort(b+1, b+m+1);
    for (int i = 1; i <= p; i++) {
        psa1[i] = psa1[i-1]+a[i];
    }
    for (int i = 1; i <= m; i++) {
        psa2[i] = psa2[i-1]+b[i];
    }

    best = 1e18L;
    for (int i = 0; i < n; i++) {
        int x = lower_bound(a+1, a+p+1, u[i].first)-a-1;
        int y = lower_bound(b+1, b+m+1, u[i].second)-b-1;
        ll cur = psa1[p]+psa2[m]-(1LL*(p-x)*u[i].first+psa1[x]+1LL*(m-y)*u[i].second+psa2[y]);
        if (cur < best) {
            best = cur;
            ans = i;
        }
    }

    cout << ans+1;
}
