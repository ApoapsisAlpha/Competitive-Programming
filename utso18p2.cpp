#include <bits/stdc++.h>

using namespace std;

int main() {
    int a[3], b[3], c[3];
    scanf("%d %d %d", &a[0], &a[1], &a[2]);
    scanf("%d %d %d", &b[0], &b[1], &b[2]);
    scanf("%d %d %d", &c[0], &c[1], &c[2]);
    
    int tot = 0;
    if (b[0] == a[2] && c[0] > 0) tot += c[0];
    if (b[1] == a[0] && c[1] > 0) tot += c[1];
    if (b[2] == a[1] && c[2] > 0) tot += c[2];
    
    printf("%d", tot);
}