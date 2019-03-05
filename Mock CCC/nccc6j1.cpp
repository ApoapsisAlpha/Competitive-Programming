#include <bits/stdc++.h>
using namespace std;

int a, b;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> a;
    cin >> b;
    if (a > b) {
        cout << "CS452\n";
    }
    else if (a < b) {
        cout << "PHIL145\n";
    }
}