#include <bits/stdc++.h>

using namespace std;

int n;
string fib[201];

string add(string a, string b) {
    string res = "";
    if (a.size() > b.size()) swap(a, b);
    int d = b.size()-a.size();

    int c = 0;
    for (int i = a.size()-1; i >= 0; i--) {
        int x = a[i]-'0'+b[i+d]-'0'+c;
        res += x%10 + '0';
        c = x/10;
    }

    for (int i = b.size()-a.size()-1; i >= 0; i--) {
        int x = b[i]-'0'+c;
        res += x%10 + '0';
        c = x/10;
    }

    if (c) res += c+'0';
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    fib[0] = "0";
    fib[1] = "1";
    for (int i = 2; i <= 200; i++) {
        fib[i] = add(fib[i-1], fib[i-2]);
    }
    
    cin >> n;
    while (n) {
        cout << fib[n] << '\n';
        cin >> n;
    }
}