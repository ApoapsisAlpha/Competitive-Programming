#include <bits/stdc++.h>

using namespace std;

int a[10000];

int n, x, y;

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        a[x] = y;
    }

    do {
        scanf("%d %d", &x, &y);
        int cur = x;
        int i = 0;
        while (a[cur]) {
            if (a[cur] == y) {
                printf("Yes %d\n", i);
                break;
            }
            if (a[cur] == x) {
                printf("No\n");
                break;
            }

            cur = a[cur];
            i++;
        }
    }
    while (x != 0 && y != 0);
    
    
}