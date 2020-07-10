#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n, x, ans;
int a[200005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    int s = 0;
    int l = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
        while (s > x) s -= a[l++];
        if (s == x) ans++;
    }

    cout << ans << "\n";
}
