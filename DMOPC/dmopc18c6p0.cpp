#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int a, b, c;


int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> c;
    if (a != 0 && b != 0 && c != 0) {
        cout << "NO\n";
        return 0;
    }

    if (a == 0) {
        if (b == 3 && c == 2) cout << "NO\n";
        else cout << "YES\n";
    }
    else if (b == 0) {
        if (a == 3 && c == 1) cout << "NO\n";
        else cout << "YES\n";
    }
    else {
        if (a == 2 && b == 1) cout << "NO\n";
        else cout << "YES\n";
    }
}
