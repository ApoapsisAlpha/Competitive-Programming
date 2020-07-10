#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n, x;
int h[1005], dp[100005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        for (int j = x; j >= h[i]; j--) {
            dp[j] = max(dp[j], dp[j-h[i]] + s);
        }
    }

    cout << dp[x] << "\n";
}
