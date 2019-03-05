#include <bits/stdc++.h>
using namespace std;

int n;
long long c, c2;
unordered_map<long long, int> m;
map<pair<long long, long long>, int> b;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        m[x]++;
        b[{x, y}]++;
    }

    for (auto i : m) {
        c += 1LL*i.second*(i.second-1)/2;
    }
    for (auto i : b) {
        c2 += 1LL*i.second*(i.second-1)/2;
    }

    cout << 1LL*n*(n-1)/2 - c + c2 << '\n';
}