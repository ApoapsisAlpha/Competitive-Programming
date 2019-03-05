#include <bits/stdc++.h>

using namespace std;

int h, k;
int houses[1000];

int solve(int len) {
    len *= 2;
    int ans = h;

    for (int i = 0; i < h && houses[i] <= houses[0]+len; i++) {
        int cur = houses[i];
        int count = 1;
        for (int j = i+1; j < h && houses[j] < 1000000+houses[i]-len; j++) {
            if (houses[j] > cur) {
                cur = houses[j] + len;
                count++;
            }
        }
        ans = min(ans, count);
    }

    return ans;
}

int main() {
    scanf("%d", &h);
    for (int i = 0; i < h; i++) {
        scanf("%d", &houses[i]);
    }
    scanf("%d", &k);

    int low = -1;
    int hi = 1000000;
    
    sort(houses, houses+h);
    
    while (low < hi-1) {
        int mid = (low+hi)/2;
        if (solve(mid) <= k) hi = mid;
        else low = mid;
    }

    printf("%d\n", hi);
}