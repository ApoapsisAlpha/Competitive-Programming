#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n, x, ans;
int a[200005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    int i = 0;
    int j = n-1;
    while (i <= j) {
        if (a[i] + a[j] > x) j--;
        else {
            i++;
            j--;
        }
        ans++;
    }

    cout << ans << "\n";
}
