#include <bits/stdc++.h>
using namespace std;

int n, ans;

int main() {
    cin >> n;
    while(n--) {
        int r, g, b;
        cin >> r >> g >> b;
        if (240 <= r && r <= 255 && 0 <= g & g <= 200 && 95 <= b && b <= 220) ans++;
    }

    cout << ans << '\n';
}