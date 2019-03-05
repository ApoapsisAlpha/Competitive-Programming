#include <bits/stdc++.h>

using namespace std;

int g, p;
set<int> a;

int main() {
    scanf("%d%d", &g, &p);

    for (int i = 1; i <= g; i++) {
        a.insert(-i);
    }

    int ans = 0;

    for (int i = 0; i < p; i++) {
        int x;
        scanf("%d", &x);
        if (*a.lower_bound(-x) == a.size()) {
            break;
        }
        a.erase(a.lower_bound(-x));
        ans++;
    }
    
    printf("%d", ans);
}