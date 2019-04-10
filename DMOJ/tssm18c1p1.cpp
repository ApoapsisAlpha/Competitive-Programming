#include <bits/stdc++.h>
using namespace std;

long long p;
string s;
vector<int> a;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    p = 1;
    for (int i = 0; i < s.size(); i++) {
        if (i%2==0) {
            a.push_back(s[i]-'0');
            p *= 1LL*(s[i]-'0');
        }
    }
    
    sort(a.begin(), a.end());
    for (int i = 0; i < s.size(); i++) {
        if (i%2) cout << 'x';
        else cout << a[i>>1];
    }
    cout << '\n';
    cout << p;
}