#include <bits/stdc++.h>
using namespace std;

int n;
char c[7];

int main() {
    for (int i = 0; i < 7; i++) {
        cin >> c[i];
        if (i == 0) continue;
        if (c[i] == 'T' && c[i] != c[i-1]) n++; 
    }

    if (c[6] == 'J') n++;
    cout << n << '\n';
}