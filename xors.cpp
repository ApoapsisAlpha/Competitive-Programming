#include <bits/stdc++.h>
using namespace std;

int n;
long long mx, mn;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mx += x;
        mn ^= x;
    }

    cout << mx-mn << '\n';
}