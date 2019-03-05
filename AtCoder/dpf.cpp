#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string a, b;
int dp[3001][3001];
pair<int, int> p[3001][3001];

int main() {
    cin >> a >> b;
    for (int i = 1; i <= a.size(); i++) {
        for (int j = 1; j <= b.size(); j++) {
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1]+1;
                p[i][j] = {i-1, j-1};
            }
            else {
                if (dp[i-1][j] > dp[i][j-1]) {
                    dp[i][j] = dp[i-1][j];
                    p[i][j] = {i-1, j};
                }
                else {
                    dp[i][j] = dp[i][j-1];
                    p[i][j] = {i, j-1};
                }
            }
        }
    }

    pair<int, int> cur = {a.size(), b.size()};
    string s = "";
    while (cur.first > 0 && cur.second > 0) {
        if (p[cur.first][cur.second] == make_pair(cur.first-1, cur.second-1)) {
            s += a[cur.first-1];
        }
        cur = p[cur.first][cur.second];
    }

    for (int i = s.size()-1; i >= 0; i--) {
        cout << s[i];
    }
}