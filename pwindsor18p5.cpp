#include <bits/stdc++.h>

using namespace std;

long long int_pow(long long x, long long p)
{
    if (p == 0) return 1;
    if (p == 1) return x;

    long long tmp = int_pow(x, p/2) % 1000000007;
    if (p%2 == 0) return tmp * tmp % 1000000007;
    else return x * tmp * tmp % 1000000007;
}

int main() {
    int n;
    scanf("%d", &n);
    
    if (n%3 == 0) {
        printf("%d", int_pow(3, n/3));
    }
    else if (n%3 == 1) {
        printf("%d", (4*int_pow(3, (n/3)-1)));
    }
    else {
        printf("%d", (2*int_pow(3, n/3)));
    }
}