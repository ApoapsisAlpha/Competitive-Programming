#include <bits/stdc++.h>

using namespace std;

string s;
int q;
int m[27][1000000];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    getline(cin, s);
    cin >> q;
    
    for (int i = 0; i < s.size(); i++) {
        for (int j = 1; j <= 26; j++) {
            if (j == (int)s[i]-96) m[j][i] = m[j][i-1] + 1;
            else m[j][i] = m[j][i-1];
        }
    }
    
    for (int i = 0; i < q; i++) {
        int a, b;
        char c;
        cin >> a >> b;
        cin >> c;
        cout << m[(int)c-96][b-1] - m[(int)c-96][a-2] << "\n";
    }
}