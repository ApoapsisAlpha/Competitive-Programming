#include <bits/stdc++.h>

using namespace std;

int n;
long long inc, exc;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        long long tmp = inc;
        inc = max(exc+x, inc);
        exc = tmp;
    }
    
    printf("%lld\n", inc);
}