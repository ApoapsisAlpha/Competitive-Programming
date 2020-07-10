
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n, ans;
int k[200005];
set<int> vis;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0, j = 0; j < n; j++) {
        cin >> k[j];
        while (vis.count(k[j])) vis.erase(k[i++]);
        vis.insert(k[j]);
        ans = max(ans, j-i+1);
    }

    cout << ans << "\n";
}
