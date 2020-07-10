#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n, m, sum, k;
int x[105];
bool dp[100005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        sum += x[i];
    }

    dp[0] = true;
    for (int i = 0; i < n; i++) {
        for (int j = sum; j >= x[i]; j--) {
            if (dp[j-x[i]] && !dp[j]) {
                dp[j] = true;
                k++;
            }
        }
    }

    cout << k << "\n";
    for (int i = 1; i <= sum; i++) {
        if (dp[i]) cout << i << " ";
    }
}
