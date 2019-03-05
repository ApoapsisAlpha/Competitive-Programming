#include <bits/stdc++.h>

using namespace std;

int n, k;
long long ans;
int f[1000001];
int a[1000001];
int l, cnt;

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (f[a[i]] == 0) cnt++;
        f[a[i]]++;
        while (cnt >= k) {
            if (f[a[l]] == 1) cnt--;
            f[a[l++]]--;
        }
        ans += l;
    }

    printf("%lld\n", ans);
}