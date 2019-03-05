#include <bits/stdc++.h>
using namespace std;

int m, d;

int main() {
    scanf("%d %d", &m, &d);
    if (m < 2) printf("Before");
    else if (m > 2) printf("After");
    else {
        if (d < 18) printf("Before");
        else if (d > 18) printf("After");
        else printf("Special");
    }
}