#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int f[4];
double dp[303][303][303];

double solve(int a, int b, int c) {
    double sum = a+b+c;
    if (sum == 0) return 0;
    if (dp[a][b][c]) return dp[a][b][c];
    dp[a][b][c] = n/sum;
    if (a) dp[a][b][c] += solve(a-1, b, c)*a/sum;
    if (b) dp[a][b][c] += solve(a+1, b-1, c)*b/sum;
    if (c) dp[a][b][c] += solve(a, b+1, c-1)*c/sum;
    return dp[a][b][c];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        f[x]++;
    }


    printf("%.10lf\n", solve(f[1], f[2], f[3]));
}