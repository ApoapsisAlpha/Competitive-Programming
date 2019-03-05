#include <bits/stdc++.h>

using namespace std;

int solve(int n) {
    switch(n&3) {
        case 0: return n;
        case 1: return 1;
        case 2: return n+1;
        case 3: return 0;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int s, f;
        scanf("%d %d", &s, &f);
        printf("%d\n", solve(s-1) ^ solve(f));
    }
}