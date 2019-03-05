#include <bits/stdc++.h>
using namespace std;

int x, n, ans;
int a[101];
int b[101];

int main() {
    scanf("%d", &x);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    
    if (x == 1) {
        sort(a, a+n);
        sort(b, b+n);
    }
    else {
        sort(a, a+n);
        sort(b, b+n, greater<int>());
    }
    
    for (int i = 0; i < n; i++) {
        ans += max(a[i], b[i]);
    }
    
    printf("%d\n", ans);
}