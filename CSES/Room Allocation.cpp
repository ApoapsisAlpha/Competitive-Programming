
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n, k;
pair<pii, int> a[200005];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int ans[200005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        a[i] = make_pair(make_pair(s, e), i);
    }

    sort(a, a+n);
    for (int i = 0; i < n; i++) {
        if (pq.empty()) {
            pq.push(make_pair(a[i].first.second, ++k));
            ans[a[i].second] = k;
        }
        else {
            auto c = pq.top();
            if (c.first < a[i].first.first) {
                pq.pop();
                pq.push(make_pair(a[i].first.second, c.second));
                ans[a[i].second] = c.second;
            }
            else {
                pq.push(make_pair(a[i].first.second, ++k));
                ans[a[i].second] = k;
            }
        }
    }

    cout << k << "\n";
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }

}
