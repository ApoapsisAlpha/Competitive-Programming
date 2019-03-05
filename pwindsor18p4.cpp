#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    cin >> a;
    cin >> b;
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int l = max(a.length(), b.length());
    for (int i = 0; i < l; i++) {
        if (a[i] != b[i]) {
            cout << a[i];
            break;
        }
    }
}