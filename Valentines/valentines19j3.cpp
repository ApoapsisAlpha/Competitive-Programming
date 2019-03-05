#include <bits/stdc++.h>
using namespace std;

string s;
string ss;
long long dp[10001][5];

int main() {
    cin >> s;
    ss = "love";
    for (int i = 0; i <= s.size(); i++) dp[i][0] = 1;
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 1; j <= 4; j++) {
            dp[i][j] = dp[i-1][j] + dp[i-1][j-1]*(s[i-1]==ss[j-1]);
        }
    }

    cout << dp[s.size()][4] << '\n';
}