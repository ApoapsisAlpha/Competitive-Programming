#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    for (int t = 0; t < 10; t++) {
        int mn = 0x3f3f3f3f;
        pair<int, vector<int>> a[701];
        vector<int> ans;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            int r;
            scanf("%d %d", &a[i].first, &r);
            for (int j = 0; j < r; j++) {
                int x;
                scanf("%d", &x);
                a[i].second.push_back(x);
                mn = min(mn, x);
            }

            sort(a[i].second.begin(), a[i].second.end());
        }

        for (int i = 0; i < n; i++) {
            if (a[i].second[0] == mn) {
                ans.push_back(a[i].first);
            }
        }

        sort(ans.begin(), ans.end());

        printf("%d {", mn);
        for (int i = 0; i < ans.size(); i++) {
            printf("%d", ans[i]);
            if (i < ans.size()-1) printf(",");
        }
        printf("}\n");
    }
}
