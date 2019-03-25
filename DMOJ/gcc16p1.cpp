#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, a, c;
ll ans;
vector<int> pos;
map<int, int> m;
pii s[100005];
pii b[100005];
int d1[400005];
int d2[400005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> a >> c;
    for (int i = 0; i < a; i++) {
        cin >> s[i].first >> s[i].second;
        pos.push_back(s[i].first);
        pos.push_back(s[i].second+1);
    }
    for (int i = 0; i < c; i++) {
        cin >> b[i].first >> b[i].second;
        pos.push_back(b[i].first);
        pos.push_back(b[i].second+1);
    }

    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());
    for (int i = 1; i <= pos.size(); i++) {
        m[pos[i-1]] = i;
    }

    for (int i = 0; i < a; i++) {
        d1[m[s[i].first]]++;
        d1[m[s[i].second+1]]--;
    }

    for (int i = 0; i < c; i++) {
        d2[m[b[i].first]]++;
        d2[m[b[i].second+1]]--;
    }

    for (int i = 1; i <= pos.size(); i++) {
        d1[i] += d1[i-1];
        d2[i] += d2[i-1];
    }

    for (int i = 1; i <= pos.size(); i++) {
        if (d1[i] && !d2[i]) {
            ans += pos[i]-pos[i-1];
        }
    }

    cout << ans << '\n';
}
