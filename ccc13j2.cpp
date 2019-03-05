#include <bits/stdc++.h>
using namespace std;

char letters[7] = {'I', 'O', 'S', 'H', 'Z', 'X', 'N' };
string s;

int main() {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        bool b = false;
        for (int j = 0; j < 7; j++) {
            if (c == letters[j]) b = true;
        }
        
        if (!b) {
            printf("NO");
            return 0;
        }
    }
    
    printf("YES");
}