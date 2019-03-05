#include <bits/stdc++.h>
using namespace std;

int n;
int tot;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        tot += x;
    }

    printf("%.1f\n", (float)tot/n);
}