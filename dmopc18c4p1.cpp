#include <bits/stdc++.h>

using namespace std;

int k, n;
float x;
double ans;

int main() {
    scanf("%d", &k);
    scanf("%f", &x);
    for (int i = 0; i < k; i++) {
        float sum = x;
        scanf("%d", &n);
        for (int j = 0; j < n; j++) {
            float d;
            scanf("%f", &d);
            sum += d;
        }
        ans += sum;
    }

    printf("%f", ans/k);
}