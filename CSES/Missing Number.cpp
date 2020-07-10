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
    int x1 = 0;
    int x2 = n;
    for (int i = 1; i <= n-1; i++) {
        int a;
        cin >> a;
        x1 ^= a;
        x2 ^= i;
    }

    cout << (x1 ^ x2) << "\n";
}

