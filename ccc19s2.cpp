#include <bits/stdc++.h>
using namespace std;

int t;

bool isPrime(int x) {
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return false;
    }

    return true;
}

int main() {
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for (int i = n; i; i--) {
            if (isPrime(i) && isPrime(2*n-i)) {
                cout << i << " " << 2*n-i;
                break;
            }
        }
        cout << "\n";
    }
}