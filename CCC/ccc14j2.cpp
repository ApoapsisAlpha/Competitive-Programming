#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int n;
string s;
int as;
int bs;

int main() {
    cin >> n;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') as++;
        else bs++;
    }
    
    if (as > bs) printf("A");
    else if (bs > as) printf("B");
    else printf("Tie");
}