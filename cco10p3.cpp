#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define omap tree<int, int, greater<int>, rb_tree_tag, tree_order_statistics_node_update>

int n, m[1000001];
omap ratings;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == 'N') {
            int x, r;
            cin >> x >> r;
            ratings[r] = x;
            m[x] = r;
        }
        else if (c == 'M') {
            int x, r;
            cin >> x >> r;
            ratings.erase(ratings.find(m[x]));
            m[x] = r;
            ratings[r] = x;
        }
        else {
            int k;
            cin >> k;
            printf("%d\n", ratings.find_by_order(k-1)->second);
        }
    }
}