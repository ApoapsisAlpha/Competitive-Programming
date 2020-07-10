#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

string s, ans;
int f[28];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        f[s[i]-'A']++;
    }

    vector<int> odds;
    for (int i = 0; i < 26; i++) {
        if (f[i]&1) odds.push_back(i);
    }

    if (odds.size() > 1) cout << "NO SOLUTION\n";
    else if (odds.size() == 1) {
        for (int i = 0; i < 26; i++) {
            if (f[i]&1) continue;
            for (int j = 0; 2*j < f[i]; j++) {
                ans += (char)(i+'A');
            }
        }
        for (int i = 0; i < f[odds[0]]; i++) {
            ans += (char)(odds[0]+'A');
        }
        for (int i = 25; i >= 0; i--) {
            if (f[i]&1) continue;
            for (int j = 0; 2*j < f[i]; j++) {
                ans += (char)(i+'A');
            }
        }
    }
    else {
        for (int i = 0; i < 26; i++) {
            if (f[i]&1) continue;
            for (int j = 0; 2*j < f[i]; j++) {
                ans += (char)(i+'A');
            }
        }
        for (int i = 25; i >= 0; i--) {
            if (f[i]&1) continue;
            for (int j = 0; 2*j < f[i]; j++) {
                ans += (char)(i+'A');
            }
        }
    }

    cout << ans << '\n';
}

