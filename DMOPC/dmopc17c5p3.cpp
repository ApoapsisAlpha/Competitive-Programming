#include <bits/stdc++.h>

using namespace std;

int n;
long long arr[100001];
long long res;

long long gcd(long long a, long long b) { 
    if (a == 0) return b; 
    return gcd(b % a, a); 
}

long long mpf(long long a) {
    long long mp = -1;
    
    while (a % 2 == 0) {
        mp = 2;
        a >>= 1;
    }

    for (long long i = 3; i*i <= a; i += 2) { 
        while (a % i == 0) {
            mp = i;
            a /= i;
        }
    }
    if (a > 2) mp = a;
    return mp;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }

    res = arr[0]; 
    for (int i = 1; i < n; i++)
        res = gcd(arr[i], res);

    if (res < 2) {
        printf("DNE");
    }
    else {
        printf("%lld", mpf(res));
    }
}