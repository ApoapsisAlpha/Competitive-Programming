#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int lx = 0x3f3f3f3f, hx = 0;
    int ly = 0x3f3f3f3f, hy = 0;

    while (n--) {
        int x, y;
        scanf("%d %d", &x, &y);

        lx = min(lx, x);
        hx = max(hx, x);
        ly = min(ly, y);
        hy = max(hy, y);
    }

    printf("%d", 2*(hy-ly + hx-lx));
}