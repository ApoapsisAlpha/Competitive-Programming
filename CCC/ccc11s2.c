#include <stdio.h>

int n, ans;
char a[10001];

int main() {
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++) {
        scanf("%c\n", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        char c;
        scanf("%c\n", &c);
        if (c == a[i]) ans++;
    }
    
    printf("%d\n", ans);
}