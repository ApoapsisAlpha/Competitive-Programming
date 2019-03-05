#include <bits/stdc++.h>
using namespace std;

string a, b;
int x[27];
int y[27];
int ans;

int main() {
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++) {
        x[a[i]-'A']++;
    }
    for (int i = 0; i < b.size(); i++) {
        y[b[i]-'A']++;
    }
    
    for (int i = 0; i < 26; i++) {
        ans += max(0, x[i]-y[i]);
    }
    
    printf("%d\n", ans);
}