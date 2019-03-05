#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, w, tot;
ll dp[100001];
int wts[101], vs[101];

int main() {
    scanf("%d %d", &n, &w);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &wts[i], &vs[i]);
        tot += vs[i];
    }

    for (int i = 1; i <= tot; i++) dp[i] = 1e18;

    for (int i = 0; i < n; i++) {
        for (int j = tot; j >= vs[i]; j--) {
            dp[j] = min(dp[j], dp[j-vs[i]]+wts[i]);
        }
    }

    int ans;
    for (int i = tot; i >= 0; i--) {
        if (dp[i] <= w) {
            ans = i;
            break;
        }
    }

    printf("%d\n", ans);
}