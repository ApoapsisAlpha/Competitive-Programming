#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    if (n%4 == 1 || n%4 == 2) cout << "NO\n";
    else {
        cout << "YES\n";
        if (n%4 == 0) {
            cout << n/2 << "\n";
            for (int i = 1; i <= n/4; i++) {
                cout << i << " " << n-i+1 << " ";
            }
            cout << "\n";
            cout << n/2 << "\n";
            for (int i = n/4 + 1; i <= n/2; i++) {
                cout << i << " " << n-i+1 << " ";
            }
        }
        else {
            cout << n/2 + 1 << "\n";
            cout << "1 2 ";
            for (int i = 1; i <= (n-3)/4; i++) {
                cout << i+3 << " " << n-i+1 << " ";
            }
            cout << "\n";
            cout << n/2 << "\n";
            cout << "3 ";
            for (int i = n/4 + 1; i <= (n-3)/2; i++) {
                cout << i+3 << " " << n-i+1 << " ";
            }
        }
    }
}

