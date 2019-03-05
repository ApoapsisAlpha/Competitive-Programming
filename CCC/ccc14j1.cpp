#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    
    if (a+b+c != 180) printf("Error");
    else if (a == b || b == c || a == c) {
        if (a == b && a == c) printf("Equilateral");
        else printf("Isosceles");
    }
    else printf("Scalene");
}