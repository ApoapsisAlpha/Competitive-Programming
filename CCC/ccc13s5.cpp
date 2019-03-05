#include <bits/stdc++.h>
using namespace std;

int n, ans;

int main() {
    scanf("%d", &n);
    if (n == 1) {
        printf("0");
        return 0;
    }

    while (n > 2) {
        for (int i = 2; i <= n; i++) {
            if (n%i == 0) {
                if (i == n) {
                    ans += n-1;
                    n--;
                }
                else {
                    n -= n/i;
                    ans += i-1;
                }
                break;
            }
        }
    }

    printf("%d\n", ans+1);
}