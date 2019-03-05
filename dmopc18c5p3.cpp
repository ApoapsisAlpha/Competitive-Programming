#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll m, sum, ans, c;
int a[200001];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (sum + a[i] < m) {
            sum += a[i];
            c++;
        }
        else if (sum > 0) {
            sum += a[i];
            sum -= a[i-c];
        }

        ans = max(ans, c);
    }

    cout << ans;
}