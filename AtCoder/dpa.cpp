#include <bits/stdc++.h>
using namespace std;

int n, h[100001];
int dp[100001];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
    }
    
    dp[1] = abs(h[1]-h[0]);
    for (int i = 2; i < n; i++) {
        dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]));
    }
    
    printf("%d\n", dp[n-1]);
}