#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n;
ll ans;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int prev;
    cin >> prev;
    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;
        ans += max(0, prev-x);
        prev = max(prev, x);
    }

    cout << ans << "\n";
}


