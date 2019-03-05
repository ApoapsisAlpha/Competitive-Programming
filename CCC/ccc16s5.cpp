#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll t;
string s;
int a[100001];
int b[100001];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> t;
    cin >> s;

    for (int i = 0; i < n; i++) {
        a[i] = s[i]-'0';
    }
    
    while (t > 0) {
        ll p2 = 1;
        while (p2<<1 < t) p2 <<= 1;
        t -= p2;
        for (int i = 0; i < n; i++) {
            b[i] = a[((i-p2)%n + n)%n]^a[(i+p2)%n];
        }
        for (int i = 0; i < n; i++) {
            a[i] = b[i];
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << a[i];
    }
}