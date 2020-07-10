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
        ll y, x;
        cin >> y >> x;
        if (y > x) {
            if (y&1) {
                cout << (y-1)*(y-1) + x << '\n';
            }
            else {
                cout << y*y - x + 1 << '\n';
            }
        }
        else {
            if (x&1) {
                cout << x*x - y + 1 << '\n';
            }
            else {
                cout << (x-1)*(x-1) + y << '\n';
            }
        }
    }
}
