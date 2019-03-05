#include <bits/stdc++.h>
using namespace std;

int x, y;

int main() {
    scanf("%d %d", &x, &y);
    if (x > 0 && y > 0) printf("1");
    else if (x < 0 && y > 0) printf("2");
    else if (x < 0 && y < 0) printf("3");
    else printf("4");
}