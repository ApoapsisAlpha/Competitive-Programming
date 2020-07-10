#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n, x, sum;
ll ans;
int m[200005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    m[0]++;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        sum += v;
        sum %= n;
        if (sum < 0) sum += n;
        ans += m[sum];
        m[sum]++;
    }

    cout << ans << "\n";
}
