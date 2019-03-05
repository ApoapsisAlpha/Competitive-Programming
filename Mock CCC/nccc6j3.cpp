#include <bits/stdc++.h>
using namespace std;

int t;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        bool f = false;
        for (int i = 0; i <= 50; i++) {
            for (int j = 0; j <= 50; j++) {
                if (i*a+j*b==c) f = true;
            }
        }
        if (f) cout << "YES\n";
        else cout << "NO\n";
    }
}