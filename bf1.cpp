#include <bits/stdc++.h>

using namespace std;

int a[1000];

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    sort(a, a+n);
    for (int i = 0; i < n; i++) {
        printf("%d\n", a[i]);
    }
}