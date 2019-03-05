#include <bits/stdc++.h>

using namespace std;

int n;
double a[1001];
double b[1001];
double ans;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }
    
    for (int i = 0; i < n; i++) {
        double d = b[i]-a[i];
        ans += d*d;
    }
    
    printf("%lf", sqrt(ans));
}