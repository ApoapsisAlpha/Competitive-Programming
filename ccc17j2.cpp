#include <bits/stdc++.h>
using namespace std;

int n, k, ans;

int main() {
    cin >> n >> k;
    k++;
    while(k--) {
        ans += n;
        n *= 10;
    }

    cout << ans;
}