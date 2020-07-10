#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

bool a[10][10];
int ans, s[10], d1[20], d2[20];

void solve(int i) {
    if (i == 8) {
        ans++;
        return;
    }

    for (int j = 0; j < 8; j++) {
        if (a[i][j] || s[j] || d1[i+j] || d2[i-j+7]) continue;
        s[j] = d1[i+j] = d2[i-j+7] = true;
        solve(i+1);
        s[j] = d1[i+j] = d2[i-j+7] = false;
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char c;
            cin >> c;
            a[i][j] = c == '*';
        }
    }

    solve(0);
    cout << ans << "\n";
}
