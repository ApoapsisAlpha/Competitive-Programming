#include <bits/stdc++.h>
using namespace std;

string s;
int sad;
int happy;

int main() {
    getline(cin, s);
    for (int i = 0; i < s.size() - 2; i++) {
        if (s[i] == ':' && s[i+1] == '-') {
            if (s[i+2] == '(') sad++;
            else if (s[i+2] == ')') happy++;
        }
    }
    
    if (happy == 0 && sad == 0) cout << "none";
    else if (happy == sad) cout << "unsure";
    else if (happy > sad) cout << "happy";
    else cout << "sad";
}