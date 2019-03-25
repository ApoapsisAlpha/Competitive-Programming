#include <bits/stdc++.h>
using namespace std;

string s;
int k, ans;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> s >> k;
    for (int i = 0, c = 1; i < s.size(); i++, c++) {
        if (i == s.size()-1 || s[i] != s[i+1]) {
            ans += max(0, c-k+1);
            c = 0;
        }
    }

    cout << ans << '\n';
}