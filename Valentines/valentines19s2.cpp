#include <bits/stdc++.h>
using namespace std;

int n, q;
int row[100001];
int col[100001];
map<pair<int, int>, int> m;

int main() {
    cin >> n >> q;
    while (q--) {
        int c, i, j;
        cin >> c >> i >> j;
        if (c == 1) {
            row[i]++;
            col[j]++;
            m[{i, j}]++;
        }
        else {
            cout << (row[i]+col[j]-m[{i, j}])%2 << '\n';
        }
    }
}