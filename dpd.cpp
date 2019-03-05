#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, w;
ll ans;
ll dp[100001];

int main() {
    scanf("%d %d", &n, &w);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        for (int j = w; j >= x; j--) {
            dp[j] = max(dp[j], dp[j-x]+y);
        }
    }

    for (int i = 0; i <= w; i++) ans = max(ans, dp[i]);
    printf("%lld", ans);
}