#include <bits/stdc++.h>

using namespace std;

int h1, w1, h2, w2;

int main() {
    scanf("%d %d", &h1, &w1);
    scanf("%d %d", &h2, &w2);
    long long a = max(0LL, 1LL*(h1-1)*w2);
    long long b = max(0LL, 1LL*(h2-1)*w1);
    
    if (a > b) printf("1");
    else if (a < b) printf("2");
    else printf("-1");
}