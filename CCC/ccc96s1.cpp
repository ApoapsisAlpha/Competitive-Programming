#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    while(n--) {
        int x;
        int tot = 0;
        scanf("%d", &x);
        for (int i = 1; i < x; i++) {
            if (x%i == 0) tot += i;
        }
        
        if (tot == x) printf("%d is a perfect number.\n", x);
        else if (tot < x) printf("%d is a deficient number.\n", x);
        else printf("%d is an abundant number.\n", x);
    }
}