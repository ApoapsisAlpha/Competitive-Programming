#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    if (n <= 5) printf("%d", 1+n/2);
    else printf("%d", 1+(10-n)/2);
}