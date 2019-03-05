#include <bits/stdc++.h>
using namespace std;

string s;
int h, v;

int main() {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'H') h++;
        else v++;
    }

    if (h%2 && v%2) {
        cout << "4 3\n";
        cout << "2 1";
    }
    else if (h%2) {
        cout << "3 4\n";
        cout << "1 2";
    }
    else if (v%2) {
        cout << "2 1\n";
        cout << "4 3";
    }
    else {
        cout << "1 2\n";
        cout << "3 4";
    }
}