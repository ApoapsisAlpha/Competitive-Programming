#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n;
int a[5005];
ll dp[5005][5005], sum;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        dp[i][i] = a[i];
        sum += a[i];
    }
    for (int i = n-1; i >= 0; i--) {
        for (int j = i+1; j < n; j++) {
            dp[i][j] = max(a[i]-dp[i+1][j], a[j]-dp[i][j-1]);
        }
    }

    cout << (dp[0][n-1] + sum)/2 << "\n";
}
