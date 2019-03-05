#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, ans;

int main() {
    scanf("%d", &n);
    while(n--) {
        int x;
        scanf("%d", &x);
        ans ^= x;
    }
    
    printf("%d\n", ans);
}