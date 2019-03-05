#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    string n;
    bool x = false;
    cin >> n;
    int i = 0;
    
    for (; i <= n.length()-4; i++) {
        if (n.substr(i, 4) == "java") {
            x = true;
            break;
        }
    }
    
    if (x) cout << i;
    else cout << n.length();
}