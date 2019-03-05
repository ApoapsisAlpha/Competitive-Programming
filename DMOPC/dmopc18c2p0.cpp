#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, r;
    scanf("%d %d %d", &n, &a, &r);
    int i = min(r/a, n);

    printf("%d", i);
}