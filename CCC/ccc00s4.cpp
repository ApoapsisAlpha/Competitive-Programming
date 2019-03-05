#include <bits/stdc++.h>

using namespace std;

int d, n;
int clubs[32];
int dp[5281];

int main() {
    scanf("%d%d", &d, &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &clubs[i]);
    }

    for (int i = 1; i <= 5280; i++) {
        dp[i] = 5280;
    }

    for (int i = 0; i <= d; i++) {
        for (int j = 0; j < n; j++) {
            if (clubs[j] + i <= d)
                dp[clubs[j]+i] = min(dp[clubs[j]+i], dp[i]+1);
        }
    }

    if (dp[d] != 5280) {
        printf("Roberta wins in %d strokes.", dp[d]);
    }
    else {
        printf("Roberta acknowledges defeat.");
    }
}