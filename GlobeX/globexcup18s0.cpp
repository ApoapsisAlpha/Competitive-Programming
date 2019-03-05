#include <bits/stdc++.h>

using namespace std;

int n;
int xs[100000];
int ys[100000];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        xs[i] = x;
        ys[i] = y;
    }

    sort(xs, xs+n);
    sort(ys, ys+n);

    int mx = xs[(n-1)>>1];
    int my = ys[(n-1)>>1];
    
    long long tot = 0;
    for (int i = 0; i < n; i++) {
        tot += abs(mx-xs[i])+abs(my-ys[i]);
    }

    printf("%lld\n", tot);
}