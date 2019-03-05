#include <bits/stdc++.h>

using namespace std;

int n, a, b;

int main() {
    a = 100;
    b = 100;
    scanf("%d", &n);
    while (n--) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x > y) b -= x;
        else if (y > x) a -= y;
    }
    
    printf("%d\n%d", a, b);
}