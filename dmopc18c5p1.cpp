#include <bits/stdc++.h>
using namespace std;

int n, m, k, b, p;

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        if (n&(1<<i) ^ m&(1<<i)) b++;
        else p++;
    }

    cout << b << " " << p;
}