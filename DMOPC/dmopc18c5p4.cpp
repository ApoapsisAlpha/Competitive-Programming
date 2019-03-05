#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
string a, b;

int main() {
    cin >> n;
    cin >> a;
    cin >> b;
    if (a == b) {
        cout << "YES";
    }
    else {
        bool x = true;
        int fa = 0, aa = 0, fb = 0, ab = 0;
        for (int i = 0; i < n-1; i++) {
            if (a[i] == a[i+1]) x = false;
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == 'F') fa++;
            else aa++;
        }
        for (int i = 0; i < n; i++) {
            if (b[i] == 'F') fb++;
            else ab++;
        }

        if (x) {
            cout << "NO";
        }
        else {
            if (fa%2 == fb%2 && aa%2 == ab%2) cout << "YES";
            else cout << "NO";
        }
    }
}