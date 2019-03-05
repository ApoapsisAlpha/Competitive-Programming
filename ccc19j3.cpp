#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;

int main() {
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        int c = 0;
        for (int i = 0; i < s.size()-1; i++) {
            c++;
            if (s[i] != s[i+1]) {
                cout << c << " " << s[i] << " ";
                c = 0;
            }
        }
        
        cout << c+1 << " " << s[s.size()-1] << "\n";
    }
}