#include <bits/stdc++.h>

using namespace std;

int a[1000], b[3000];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    for (int i = 0; i < m; i++) {
        scanf("%d", &b[i]);
    }
    
    sort(a, a+n);
    sort(b, b+m);
    
    int tmp = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x = lower_bound(b, b+m, a[i]) - b;
        int d;
        if (x == 0)
            d = b[x] - a[i];
        else if (x >= m-1)
            d = a[i] - b[x-1];
        else
            d = min(b[x] - a[i], a[i] - b[x-1]);
        
        if (d > tmp) {
            tmp = d;
            ans = a[i];
        }
    }
    
    printf("%d", ans);
}