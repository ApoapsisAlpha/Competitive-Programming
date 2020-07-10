
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n;
ll mx, sum;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        mx = max(mx, x);
        sum += x;
    }

    cout << max(2*mx, sum) << "\n";
}
