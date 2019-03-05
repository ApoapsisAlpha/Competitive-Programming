#include <bits/stdc++.h>
using namespace std;

int n, ans, c;

int main() {
    c = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            scanf("%d", &x);
            if (x != c) ans++;
            c++;
        }
    }

    printf("%d\n", (int)ceil(sqrt(ans)));
}