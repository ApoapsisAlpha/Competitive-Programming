#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    
    int i = 0;
    while (n--) {
        int x;
        scanf("%d", &x);
        bool p = true;
        for (int i = 2; i <= x/2; i++) {
            if (x%i==0) {
                p = false;
                break;
            }
        }
        
        if (!p) i++;
    }
    
    printf("%d", i);
}