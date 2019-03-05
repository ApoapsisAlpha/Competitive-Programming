#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k;
int a[100001];
bool dp[100001];

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= a[j] && !dp[i-a[j]]) dp[i] = true;
        }
    }

    if (dp[k]) printf("First");
    else printf("Second");
}