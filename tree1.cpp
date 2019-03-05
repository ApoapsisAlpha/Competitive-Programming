#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int tot;
bool vis[4];
int n;

int main() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int x;
            scanf("%d", &x);
            tot += x;
            if (x && !vis[i]) {
                vis[i] = true;
                n++;
            }
        }
    }
    
    if (tot == 2*(n-1)) printf("Yes");
    else printf("No");
}