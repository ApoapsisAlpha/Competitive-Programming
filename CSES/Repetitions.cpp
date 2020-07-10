#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

string s;
int ans;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    ans = 1;
    int cur = 1;
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == s[i-1]) cur++;
        else cur = 1;
        ans = max(ans, cur);
    }

    cout << ans << '\n';
}

