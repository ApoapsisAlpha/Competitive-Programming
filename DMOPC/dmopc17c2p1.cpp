#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    scanf("%d", &n);
    
    long long tot = 0;
    for (int i = 0; i < n; i++) {
        int c, v;
        scanf("%d %d", &c, &v);
        
        if (v > 0) {
            tot += c;
        }
    }
    
    printf("%lld", tot);
}