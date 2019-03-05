#include <bits/stdc++.h>

using namespace std;

int n, m, ans;
vector<int> good;
vector<int> bad;
vector<long long> goodsum;
vector<long long> badsum;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int s, p;
        scanf("%d %d", &s, &p);
        if (p == 2) {
            good.push_back(s);
        }
        else {
            bad.push_back(s);
        }
    }
    
    sort(good.begin(), good.end());
    sort(bad.begin(), bad.end());

    for (int i = 0; i < good.size(); i++) {
        if (i == 0) goodsum.push_back(good[i]);
        else goodsum.push_back(good[i] + goodsum[i-1]);
    }

    for (int i = 0; i < bad.size(); i++) {
        if (i == 0) badsum.push_back(bad[i]);
        else badsum.push_back(bad[i] + badsum[i-1]);
    }

    goodsum.insert(goodsum.begin(), 0);
    badsum.insert(badsum.begin(), 0);
    
    for (int i = 0; i < goodsum.size(); i++) {
        if (m-goodsum[i] < 0) break;
        int lo = 0;
        int hi = badsum.size()-1;
        while (lo <= hi) {
            int mid = (lo+hi)/2;
            if (badsum[mid] <= m-goodsum[i]) lo = mid+1;
            else hi = mid - 1;
        }

        ans = max(ans, 2*i+hi);
    }
    
    printf("%d\n", ans);
}