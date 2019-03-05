#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i < n; i++) {
        printf("0 ");
    }
    
    printf("%d", k);
}