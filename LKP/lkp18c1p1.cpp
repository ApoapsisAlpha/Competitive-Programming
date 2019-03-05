#include <bits/stdc++.h>

using namespace std;

int n, k, ans;
int a[10];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int cur = n-1;
    while (k > 0 && cur >= 0) {
        if (k/a[cur] >= 1) {
            ans += (int)(k/a[cur]);
            k -= (int)(k/a[cur]) * a[cur];
        }
        cur--;
    }
    
    if (k != 0) printf("-1\n");
    else printf("%d\n", ans);
    
}