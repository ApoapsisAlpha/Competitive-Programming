#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, k, ans;
int arr[200001];
int mods[50001];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    ll sum = 0;
    for (int i = 0; i < n; i++) { 
        sum += arr[i]; 
        mods[sum%k]++;
    }
    
    for (int i = 0; i < k; i++) {
        if (mods[i] > 1) {
            ans += (mods[i] * (mods[i] - 1))/2;
        }
    }

    printf("%d\n", ans+mods[0]);
}