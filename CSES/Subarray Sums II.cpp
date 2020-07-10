#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n, x;
ll sum, ans;
map<ll, int> m;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    m[0]++;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        sum += v;
        ans += m[sum - x];
        m[sum]++;
    }

    cout << ans << "\n";
}
