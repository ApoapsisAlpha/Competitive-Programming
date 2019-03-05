#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[1000001];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        char c;
        scanf(" %c", &c);
        
        if(c == 'S')
            a[i] = 0;
        else if(c == 'M')
            a[i] = 1;
        else if(c == 'L')
            a[i] = 2;
    }
    
    int ans = 0;
    for(int i = 1; i <= m; i++)
    {
        int x;
        char c;
        scanf(" %c%d", &c, &x);
        int s = 0;
        
        if(c == 'M')
            s = 1;
        else if(c == 'L')
            s = 2;
        if(1 <= x && x <= n && a[x] >= s) {
            ans++;
            a[x] = -1;
        }
    }
    
    printf("%d\n", ans);
    return 0;
}