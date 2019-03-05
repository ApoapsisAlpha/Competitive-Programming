#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
double dp[3000], ans;

int main() {
    scanf("%d", &n);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        double p;
        scanf("%lf", &p);
        for (int i = n; i > 0; i--) {
            dp[i] = (1-p)*dp[i] + p*dp[i-1];
        }
        dp[0] *= (1-p);
    }

    for (int i = 1; i <= n; i++) {
        if (i > (n-i)) {
            ans += dp[i];
        }
    }

    printf("%.10lf", ans);
}