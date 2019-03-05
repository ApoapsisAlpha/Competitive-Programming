#include <bits/stdc++.h>

using namespace std;

bool is_prime(int x) {
    if (x <= 1) return false;
    for (int i = 2; i < sqrt(x); i++) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    int n;
    scanf("%d", &n);
    while(1) {
        if (is_prime(n++)) break;
    }
    
    printf("%d", n-1);
    
}