#include <bits/stdc++.h>

using namespace std;

int t, c, ans;
int a[101];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> t >> c;
    for (int i = 0; i < c; i++) {
        cin >> a[i];
    }
    
    sort(a, a+c);
    int sum = 0;
    for (int i = 0; i < c; i++) {
        if (sum + a[i] > t) break;
        sum += a[i];
        ans++;
    }
    
    cout << ans;
}