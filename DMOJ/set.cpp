#include <bits/stdc++.h>

using namespace std;

int n;
unordered_set<int> s;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        s.insert(x);
    }
    
    printf("%d\n", s.size());
}