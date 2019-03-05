#include <bits/stdc++.h>

using namespace std;

int n, m;
int farms[100000];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &farms[i]);
    }
    
    sort(farms, farms+n);
    
    long long tot = 0;
    for (int i = m; i < n; i++) {
        tot += farms[i];
    }
    
    printf("%lld\n", tot);
}