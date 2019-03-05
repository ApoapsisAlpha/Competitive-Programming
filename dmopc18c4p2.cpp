#include <bits/stdc++.h>

using namespace std;

int n, sum, ans;
int a[702];
bitset<490002> dp[702];

int main() {
    ans = 0x3f3f3f3f;    
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
    }

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= sum; i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            dp[i][j] = dp[i-1][j];
            if (a[i-1] <= j) {
                dp[i][j] = dp[i][j] | dp[i-1][j-a[i-1]];
            }
        }
    }

    for (int i = sum>>1; i >= 0; i--) {
        if (dp[n][i]) {
            ans = sum-2*i;
            break;
        }
    }

    printf("%d\n", ans);
}