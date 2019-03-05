#include <bits/stdc++.h>

using namespace std;

int n, d, ans;
int lengths[10000];

int main() {
    scanf("%d %d", &n, &d);
    d = abs(d);
    for (int i = 0; i < n; i++) {
        scanf("%d", &lengths[i]);
    }
    
    for (int i = 0; i < n; i++) {
        if (d % lengths[i] == 0) ans = max(ans, lengths[i]);
    }
    
    if (ans == 0)
        printf("This is not the best time for a trip.");
    else
        printf("%d", d/ans);
    
}