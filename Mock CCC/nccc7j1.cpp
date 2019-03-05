#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    for (int i = 0; i < 5; i++) {
        char c;
        scanf("%c\n", &c);
        if (c == 'P') n++;
    }

    printf("%d\n", n);
}