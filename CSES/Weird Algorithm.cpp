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
    cout << n << " ";
    while (n != 1) {
        if (n&1) {
            n *= 3;
            n++;
        }
        else {
            n >>= 1;
        }
        cout << n << " ";;
    }
}
