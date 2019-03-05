#include <bits/stdc++.h>

using namespace std;

int n, q;
int presum[1000000];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &q);
        presum[i] = q+presum[i-1];
    }
    
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", presum[b+1] - presum[a]);
    }
    
}