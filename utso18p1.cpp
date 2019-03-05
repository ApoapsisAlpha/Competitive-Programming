#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, m;
    scanf("%lld %lld", &n, &m);
    
    printf("%lld", max(n*m, max(abs(n-m), n+m)));
}