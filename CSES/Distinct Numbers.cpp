#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n, ans;
int a[200005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);

    ans = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i-1]) ans++;
    }

    cout << ans << "\n";
}
