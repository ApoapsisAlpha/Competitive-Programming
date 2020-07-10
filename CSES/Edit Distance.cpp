#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

string s1, s2;
int dp[5005][5005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> s1 >> s2;
    for (int i = 1; i <= s1.size(); i++) dp[i][0] = i;
    for (int i = 1; i <= s2.size(); i++) dp[0][i] = i;
    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
            dp[i][j] = min(dp[i][j], dp[i-1][j-1] + (s1[i-1] != s2[j-1]));
        }
    }

    cout << dp[s1.size()][s2.size()] << "\n";
}
