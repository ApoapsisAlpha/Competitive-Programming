#include <bits/stdc++.h>
using namespace std;

int n, k, mn;
char c;
string s;
int freq[27];

int main() {
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;
    }

    mn = 0x3f3f3f3f;
    for (char i = 'a'; i <= 'z'; i++) {
        if (freq[i-'a'] < mn) {
            mn = freq[i-'a'];
            c = i;
        }
    }

    if (mn > k || k > n) cout << "WRONGANSWER";
    else {
        for (int i = 0; i < n-k; i++) {
            cout << c;
        }

        for (int i = 0; i < k; i++) {
            cout << s[i];
        }
    }
}