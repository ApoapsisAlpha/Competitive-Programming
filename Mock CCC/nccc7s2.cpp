#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll x, y, x1, z, x2, y2;
double ans;

double dist(ll a1, ll b1, ll a2, ll b2) {
    return sqrt((a2-a1)*(a2-a1)+(b2-b1)*(b2-b1));
}

int main() {
    scanf("%lld %lld %lld %lld %lld %lld", &x, &y, &x1, &z, &x2, &y2);

    if (x >= x2) {
        if (y >= y2) {
            ans = dist(x, y, x2, y2);
        }
        else if (y <= z) {
            ans = dist(x, y, x2, z);
        }
        else {
            ans = x-x2;
        }
    }
    else if (x <= x1) {
        if (y >= y2) {
            ans = dist(x, y, x1, y2);
        }
        else if (y <= z) {
            ans = dist(x, y, x1, z);
        }
        else {
            ans = x1-x;
        }
    }
    else {
        ans = min(abs(y-y2), abs(y-z));
    }
    
    printf("%.3lf\n", ans);
}