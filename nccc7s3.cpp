#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll ans;
ll xs[3001];
ll ys[3001];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &xs[i], &ys[i]);
    }

    for (int i = 0; i < n; i++) {
        map<pair<ll, ll>, ll> m;
        for (int j = i+1; j < n; j++) {
            ll dx = xs[i]-xs[j];
            ll dy = ys[i]-ys[j];

            ll g = __gcd(dx, dy);
            dx /= g;
            dy /= g;
            
            m[{dx, dy}]++;
        }

        ll c = (n-i-1)*(n-i-2)/2;
        for (auto j : m) c -= j.second*(j.second-1)/2;

        ans += c;
    }

    printf("%lld\n", ans);
}