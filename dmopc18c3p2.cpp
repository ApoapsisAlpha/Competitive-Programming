#include <bits/stdc++.h>

using namespace std;

int n;
int sum[100000];
int a[100000];
int b[100000];
int d[100000];
int bsum;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
        d[i] = a[i] - b[i];
        bsum += b[i];
    }

    if (n >= 1) {
        if (d[0] > 0)
            sum[0] = d[0];
    }

    if (n >= 2) {
        if (d[1] > 0)
            sum[1] = d[1] + sum[0];
        else
            sum[1] = sum[0];
    }

    if (n >= 3) {
        if (d[2] > 0)
            sum[2] = max(sum[1], max(d[1] + d[2], sum[0] + d[2]));
        else
            sum[2] = sum[1];
    }

    for (int i = 3; i < n; i++) {
        if (d[i] > 0)
            sum[i] = max(max(sum[i - 1], sum[i - 2] + d[i]), d[i] + d[i - 1] + sum[i - 3]);
        else
            sum[i] = sum[i - 1];
    }

    printf("%d\n", sum[n - 1] + bsum);
}