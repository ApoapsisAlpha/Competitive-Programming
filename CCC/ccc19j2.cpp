#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

int main() {
    cin >> n;
    while(n--) {
        int x;
        char c;
        cin >> x >> c;
        for (int i = 0; i < x; i++) cout << c;
        cout << "\n";
    }
}