#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    for (int i = 0; i < 6; i++) {
        char c;
        scanf("%c\n", &c);
        if (c == 'W') n++;
    }
    
    if (n == 0) printf("-1");
    else if (n < 3) printf("3");
    else if (n < 5) printf("2");
    else printf("1");
}