#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
int arr[101];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < m; i++) {
        sort(arr, arr+n);
        printf("%d\n", arr[0]);
        arr[0]++;
    }
}