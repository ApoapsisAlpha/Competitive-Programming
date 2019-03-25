#include <bits/stdc++.h>
using namespace std;

int n, m;

int main() {
    scanf("%d %d", &n, &m);
    if (n < m) printf("%d\n", n);
    else printf("%d\n", m-1);
}