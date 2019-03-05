#include <bits/stdc++.h>

using namespace std;

vector<int> primes;

int main() {
    int n;
    scanf("%d", &n);
    
    while (n--) {
        int m;
        scanf("%d", &m);
        
        while (m % 2 == 0) {
            printf("2 ");
            m /= 2;
        }
        
        for (int i = 3; i*i <= m; i += 2) {
            while (m % i == 0) { 
                printf("%d ", i);
                m /= i;
            }
        }
        
        if (m > 2) printf("%d", m);
        printf("\n");
    }
}