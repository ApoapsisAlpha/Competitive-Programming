#include <bits/stdc++.h>

using namespace std;

int n;

double dist(long long x1, long long y1, long long x2, long long y2) {
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

int main() {
    scanf("%d", &n);
    
    while(n--) {
        long long x[3];
        long long y[3];
        scanf("%lld %lld %lld %lld %lld %lld", &x[0], &y[0], &x[1], &y[1], &x[2], &y[2]);
        
        double area = abs(0.5*(x[0]*y[1]+x[1]*y[2]+x[2]*y[0]-x[0]*y[2]-x[2]*y[1]-x[1]*y[0]));
        double perimeter = dist(x[0], y[0], x[1], y[1]) + dist(x[1], y[1], x[2], y[2]) + dist(x[0], y[0], x[2], y[2]);
        printf("%.2f %.2f\n", area, perimeter);
    }
}