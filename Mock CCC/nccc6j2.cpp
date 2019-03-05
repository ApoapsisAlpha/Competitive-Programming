#include <bits/stdc++.h>
using namespace std;

string s;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    string p = "pusheen";
    int c = 0;
    for (int i = 0; i < 7; i++) {
        if (p[i] != s[i]) c++;
    }

    cout << c << '\n';
}