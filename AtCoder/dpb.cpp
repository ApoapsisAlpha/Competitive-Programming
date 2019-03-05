#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
int a[100001];
int dp[100001];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[0] = 0;
    for(int i = 1; i < n; i++) {
        for (int j = 1; j <= k && i-j >= 0; j++) {
            dp[i] = min(dp[i], dp[i-j] + abs(a[i-j]-a[i]));
        }
    }

    printf("%d\n", dp[n-1]);
}