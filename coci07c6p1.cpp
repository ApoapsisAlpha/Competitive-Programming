#include <bits/stdc++.h>

using namespace std;

int n;

int a, b, c, last, first = 0x3f3f3f3f;
int l[3];
int r[3];

int main() {
    scanf("%d %d %d", &a, &b, &c);
    for (int i = 0; i < 3; i++) {
        scanf("%d %d", &l[i], &r[i]);
        last = max(last, r[i]);
        first = min(first, l[i]);
    }
    
    int tot = 0;
    
    for (int i = first; i <= last; i++) {
        int count = 0;
        for (int j = 0; j < 3; j++) {
            if (l[j] <= i && i < r[j]) count++;
        }
        
        switch (count) {
            case 1: tot += a; break;
            case 2: tot += 2*b; break;
            case 3: tot += 3*c; break;
        }
    }
    
    printf("%d\n", tot);
    
}