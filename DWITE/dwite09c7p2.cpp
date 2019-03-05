#include <bits/stdc++.h>

using namespace std;

int n;
bool primes[100001];

int main() {
    memset(primes, true, 100001);
    primes[1] = false;
    
    for (int i = 2; i*i <= 100000; i++) {
        if (primes[i]) {
            for (int j = i*i; j <= 100000; j += i) {
                primes[j] = false;
            }
        }
    }
    
    for (int i = 0; i < 5; i++) {
        scanf("%d", &n);
        int tot = 0;
        for (int i = 1; i <= n; i++) {
            if (primes[i]) tot += i;
        }
        
        printf("%d\n", tot);
    }
    
}