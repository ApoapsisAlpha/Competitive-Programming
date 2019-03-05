#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int lcp(string a, string b) {
    int x = min(a.size(), b.size());
    for (int i = 0; i < x; i++) {
        if (a[i] != b[i]) return i;
    }

    return x;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        vector<string> suf(s.size());
        for (int j = 0; j < s.size(); j++) {
            suf[j] = s.substr(j, s.size()-j);
        }

        sort(suf.begin(), suf.end());

        int ans = 1 + suf[0].size();
        for (int j = 1; j < s.size(); j++) {
            ans += suf[j].size() - lcp(suf[j], suf[j-1]);
        }

        cout << ans << '\n';
    }
}