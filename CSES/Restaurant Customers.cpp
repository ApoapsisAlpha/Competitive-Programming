#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n, ans;
vector<pair<int, bool>> a;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        a.push_back({x, true});
        a.push_back({y, false});
    }

    sort(a.begin(), a.end());

    int cur = 0;
    for (int i = 0; i < 2*n; i++) {
        if (a[i].second) cur++;
        else cur--;
        ans = max(ans, cur);
    }

    cout << ans << "\n";
}
