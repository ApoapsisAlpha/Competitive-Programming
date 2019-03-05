#include <bits/stdc++.h>

using namespace std;

unsigned long long n;

unsigned long long fastpow2(unsigned long long n) {
    unsigned long long pow2 = 2;
    unsigned long long res = 1;
    while (n) {
        if (n & 1) {
            res = (res * pow2) % 1000000007;
        }
        pow2 = (pow2 * pow2) % 1000000007;
        n >>= 1;
    }
    
    return res;
}

int main() {
    scanf("%lld", &n);
    printf("%lld", fastpow2(n+3)-5);
    
}