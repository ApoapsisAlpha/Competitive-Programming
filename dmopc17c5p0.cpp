#include <bits/stdc++.h>

using namespace std;

int b, p;
char c;

int main() {
    scanf("%d%d\n", &b, &p);
    scanf("%c", &c);

    if (c == 'N') {
        if (b/p >= 5) {
            printf("A");
        }
        else if (b/p >= 2) {
            printf("C");
        }
        else {
            printf("NO PIZZA");
        }
    }
    else {
        if (b/p >= 5) {
            printf("B");
        }
        else if (b/p >= 2) {
            printf("D");
        }
        else {
            printf("NO PIZZA");
        }
    }
}