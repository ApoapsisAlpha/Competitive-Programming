#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        if (n %i == 0) tot += i;
    }
    
    printf("%d", tot);
}