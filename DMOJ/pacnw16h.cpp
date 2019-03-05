#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;

ll n, k;
ll dp[200001];
pl a[200001];

bool cmp(ll v, pl t) { 
    return v <= t.first; 
}

int main() {
    scanf("%lld %lld", &n, &k);
    
    for(int i = 1; i <= k; i++) {
        scanf("%lld %lld", &a[i].second, &a[i].first);
    }
    
    sort(a+1, a+k+1);
    for (int i = 1; i <= k; i++) {
        int cur = upper_bound(a+1, a+i+1, a[i].second, cmp) - a - 1;
        dp[i] = max(dp[i-1], dp[cur] + a[i].first - a[i].second + 1);
    }
    
    printf("%lld\n", n - dp[k]);
}