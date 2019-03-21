#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    for (int tc = 0; tc < 10; tc++) {
        int t, n, days, boxqueue, ans;
        cin >> t >> n;
        days = boxqueue = ans = 0;
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            if (c == 'B') boxqueue++;
            if (boxqueue) days++;
            if (days == t) {
                boxqueue--;
                days = 0;
            }
        }

        ans += t-days;
        boxqueue--;
        if (boxqueue) {
            ans += boxqueue*t;
        }

        cout << ans << '\n';
    }
}
