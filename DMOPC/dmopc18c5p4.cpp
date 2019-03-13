#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
string s;
bool a[200001];
bool b[200001];

int main() {
    cin >> n;
    cin >> s;
    for (int i = 1; i <= n; i++) {
        a[i] = s[i-1] == 'F';
    }
    cin >> s;
    for (int i = 1; i <= n; i++) {
        b[i] = s[i-1] == 'F';
    }

    int x = 1;
    for (int i = 1; i < n; i++) {
        if (x < i) x = i;
        if (a[i] != b[i]) {
            while (x < n) {
                if (a[x] == a[x+1]) {
                    a[x+1] = !a[x+1];
                    break;
                }
                x++;
            }
            if (x == n) {
                cout << "NO";
                return 0;
            }
        }
    }

    if (a[n] != b[n]) {
        cout << "NO";
    }
    else {
        cout << "YES";
    }
}