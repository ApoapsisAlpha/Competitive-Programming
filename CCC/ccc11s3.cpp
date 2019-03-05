#include <bits/stdc++.h>
using namespace std;

int t;

bool solve(int m, int x, int y) {
    if (m == 0) return false;

    int s = pow(5, m-1);
    int a = x/s;
    int b = y/s;
    if (a == 1 || a == 3) {
        if (b == 0) {
            return true; 
        }
        else if (b == 1) {
            return solve(m-1, x%s, y%s);
        }
    }
    else if (a == 2) {
        if (b < 2) {
            return true;
        }
        else if (b == 2) {
            return solve(m-1, x%s, y%s);
        }
    }

    return false;
}

int main() {
    scanf("%d", &t);
    while(t--) {
        int m, x, y;
        scanf("%d %d %d", &m, &x, &y);
        if (solve(m, x, y)) {
            printf("crystal\n");
        }
        else {
            printf("empty\n");
        }
    }
}