#include <bits/stdc++.h>

using namespace std;

int m, n, k;
vector<long long> heights;

int main() {
    scanf("%d %d %d", &m, &n, &k);

    for (int i = 0; i < k; i++) {
        int h;
        scanf("%d", &h);
        heights.push_back(h);
    }

    sort(heights.begin(), heights.end());

    long long tot = 0;
    int l = 0;
    int r = k-1;

    for (int i = 0; i < n; i++) {
        long long a = heights[r];
        long long cushion = 0;
        for (int i = 1; i < m; i++) {
            if (l < r) {
                cushion += a - heights[l++] + 1;
                a++;
            }
            else break;
        }
        r--;
        tot += cushion;

        if (l > r) break;
    }

    printf("%lld", tot);
    
}