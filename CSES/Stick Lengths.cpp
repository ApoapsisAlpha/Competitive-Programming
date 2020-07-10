#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n;
ll ans;
int a[200005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int m = a[n/2];
    for (int i = 0; i < n; i++) {
        ans += abs(a[i]-m);
    }

    cout << ans << "\n";
}
