#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, ans;
string s1;
string s2;

int main() {
    cin >> n;
    cin >> s1;
    cin >> s2;
    for (int i = 0; i < n; i++) {
        if (s1[i] == 'C' && s2[i] == 'C') ans++;
    }
    
    cout << ans;
}