#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    long long a = 0;
    long long b = 0;
    while(n--) {
        long long x, y;
        cin >> x >> y;
        if (x*x+y*y > a*a+b*b) {
            a = x;
            b = y;
        }
    }
    
    cout << a << " " << b;
}