#include <bits/stdc++.h>
using namespace std;

int n;
int a[100001];

bool cmp(int a, int b) {
    string x = to_string(a);
    string y = to_string(b);
    if (x[x.size()-1] == y[y.size()-1]) {
        return a/10 > b/10;
    }
    
    return x[x.size()-1] < y[y.size()-1];
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    sort(a, a+n, cmp);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
}