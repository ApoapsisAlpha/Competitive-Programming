#include <bits/stdc++.h>

using namespace std;

int m;
unsigned long long sum;

int main() {
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        long long x;
        scanf("%lld", &x);
        x = -x;
        sum += x;
    }
    
    if (sum == 0) printf("0");
    else printf("-%llu", sum);
}