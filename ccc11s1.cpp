#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
string s;
int ts, ss;

int main() {
    cin >> n;
    cin.ignore();
    while(n--) {
        getline(cin, s);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'T' || s[i] == 't') ts++;
            if (s[i] == 'S' || s[i] == 's') ss++;
        }
    }
    
    if (ts > ss) cout << "English\n";
    else cout << "French\n";
}