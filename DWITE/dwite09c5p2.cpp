#include <bits/stdc++.h>

using namespace std;

int n;
bool primes[110];


int main() {
    memset(primes, true, sizeof(primes));
    
    for (int i = 2; i*i <= 110; i++) {
        if (primes[i]) {
            for (int j = i*2; j <= 110; j += i)
                primes[j] = false;
        }
    }
    
    for (int i = 0; i < 5; i++) {
        scanf("%d", &n);
        int l = n-1, h = n+1;
        while(!primes[l]) l--;
        l--;
        while(!primes[l]) l--;
        
        while(!primes[h]) h++;
        h++;
        while(!primes[h]) h++;
        
        
        if (h-n <= n-l)
            printf("%d\n", h);
        else
            printf("%d\n", l);
    }
}