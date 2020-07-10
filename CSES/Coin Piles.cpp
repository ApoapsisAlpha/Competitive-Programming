#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int t;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if (a < b) swap(a, b);
        if (2*b - a >= 0 && (2*b)%3 == a%3) cout << "YES\n";
        else cout << "NO\n";
    }
}
