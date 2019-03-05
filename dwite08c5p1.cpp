#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 0; i < 5; i++) {
        string a, b;
        getline(cin, a);
        getline(cin, b);
        int c = 0;
        
        if (a.length() > b.length()) {
            for (int i = 0; i < b.length(); i++) {
                if (a[i] != b[i]) break;
                c++;
            }
        }
        else {
            for (int i = 0; i < a.length(); i++) {
                if (a[i] != b[i]) break;
                c++;
            }
        }
        cout << c << "\n";
    }
}