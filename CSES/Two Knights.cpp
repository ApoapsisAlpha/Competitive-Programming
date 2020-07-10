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

    for (int i = 1; i <= n; i++) {
        ll total = (ll)i*i*(i*i - 1)/2;
        int blocks = i > 2 ? 4*(i-1)*(i-2) : 0;
        cout << total - blocks << "\n";
    }
}
