#include <bits/stdc++.h>

using namespace std;

int n;
long long ans;
int a[50001];
int b[50001];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    
    sort(a, a+n);
    sort(b, b+n);
    
    for (int i = 0; i < n; i++) {
        ans += 1LL*a[i]*b[n-i-1];
    }
    
    printf("%lld\n", ans);
}