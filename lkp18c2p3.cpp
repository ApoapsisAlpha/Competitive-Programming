#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
pair<int, int> pts[101];

double area(int x1, int y1, int x2, int y2, int x3, int y3) {
   return abs((1LL*x1*(y2-y3)+1LL*x2*(y3-y1)+1LL*x3*(y1-y2))/2.0);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pts[i].first, &pts[i].second);
    }

    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2, x3, y3;
        scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

        int res = 0;
        for (int j = 0; j < n; j++) {
            int x = pts[j].first;
            int y = pts[j].second;
            double a = area(x1, y1, x2, y2, x3, y3); 
            double a1 = area(x, y, x2, y2, x3, y3); 
            double a2 = area(x1, y1, x, y, x3, y3); 
            double a3 = area(x1, y1, x2, y2, x, y); 
            res += (a == a1 + a2 + a3);
        }

        printf("%d\n", res);
    }
}