#include <bits/stdc++.h>
using namespace std;

int n, b, c, ans;
bool found;
int a[100001];
unordered_map<int, int> m;

int main() {
    scanf("%d %d", &n, &b);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        if (found) {
            c += a[i] < b ? 1 : -1;
            ans += m[-c];
            if (c == 0) ans++;
        }
        
        if (a[i] == b) {
            found = true;
            for (int j = i-1; j >= 0; j--) {
                c += a[j] < b ? 1 : -1;
                m[c]++;

                if (c == 0) ans++;
            }
            
            c = 0;
        }
    }
    
    printf("%d\n", ans+1);
}