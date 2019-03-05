#include <bits/stdc++.h>

using namespace std;

int n;
char a[20];
string b[20];
string seq;
string res;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    cin >> seq;

    res = "";
    int j = 0;
    while (j < seq.length()) {
        for (int i = 0; i < n; i++) {
            if (b[i] == seq.substr(j, b[i].length())) {
                res += a[i];
                j += b[i].length();
            }
        }
    }

    cout << res;
}