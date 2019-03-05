#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a, b;

int main() {
    for (int i = 3; i; i--) {
        int x;
        cin >> x;
        a += x*i;
    }
    for (int i = 3; i; i--) {
        int x;
        cin >> x;
        b += x*i;
    }
    
    if (a > b) cout << "A";
    else if (a < b) cout << "B";
    else cout << "T";
}