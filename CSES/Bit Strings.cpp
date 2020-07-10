#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int mod = 1e9 + 7;
int n, ans;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    ans = 1;
    for (int i = 0; i < n; i++) {
        ans <<= 1;
        if (ans > mod) ans -= mod;
    }

    cout << ans << "\n";
}

