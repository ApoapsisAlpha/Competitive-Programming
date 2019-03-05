#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    for (int i = 0; i < 5; i++) {
        cin >> n;
        int x = __builtin_popcount(n);
        for (int i = 0; i < 32; i++) {
            if (__builtin_popcount(n+(1<<i)) == x) {
                n += (1<<i);
                break;
            }
        }
        
        cout << n << '\n';
    }
}