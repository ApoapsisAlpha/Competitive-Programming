#include <bits/stdc++.h>

using namespace std;

int n;
int arr[101];
double ans;

int main() {
    ans = 0x3f3f3f3f;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    sort(arr, arr+n);
    
    for (int i = 1; i < n-1; i++) {
        ans = min(ans, (arr[i+1]-arr[i-1])/2.0);
    }
    
    printf("%.1f\n", ans);
}