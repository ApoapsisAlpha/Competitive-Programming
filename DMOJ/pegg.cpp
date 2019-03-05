#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int t, n, k;
ll dp[33][33];

int main() {
    scanf("%d", &t);
    for (int i = 0; i <= 32; i++) {
        dp[i][0] = 1;
        dp[0][i] = 1;
    }

    for (int i = 1; i <= 32; i++) {
        for (int j = 1; j <= 32; j++) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }

    while(t--) {
        scanf("%d %d", &n, &k);
        int l = 0;
        int h = 32;
        while (l <= h) {
            int mid = (l+h)>>1;
            if (dp[mid][k] <= n) l = mid+1;
            else h = mid-1;
        }

        if (l > 32) printf("Impossible\n");
        else printf("%d\n", l);
    }
}