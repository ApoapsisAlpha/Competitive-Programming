#include <bits/stdc++.h>

using namespace std;

int i, s, x;
double tot;

int main() {
    scanf("%d", &i);
    for (int j = 0; j < i; j++) {
        scanf("%d", &x);
        tot += x;
    }
    
    scanf("%d", &s);
    for (int j = 0; j < s; j++) {
        scanf("%d", &x);
        printf("%.3f\n", (tot+=x)/++i);
    }
    
}