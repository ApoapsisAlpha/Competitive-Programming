#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int n;
bool t, u, neither;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == 'T') t = true;
        else if (c == 'U') u = true;
        if (c != 'T' && c != 'U' && c != 'A' && c != 'G' && c != 'C') neither = true;
    }

    if ((t && u) || neither) {
        cout << "neither\n";
    }
    else if (t) {
        cout << "DNA\n";
    }
    else if (u) {
        cout << "RNA\n";
    }
    else {
        cout << "both\n";
    }
}
