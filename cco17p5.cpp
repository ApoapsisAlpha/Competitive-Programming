#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, ans, c;
vector<pii> a;

bool cmp(const pii& a, const pii& b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (c >= x || y == 0) {
            c++;
        }
        else {
            a.push_back({x, y});
        }
    }

    sort(a.begin(), a.end(), cmp);

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < a.size(); i++) {
        pq.push(a[i].second);
        if (c+a.size()-i-1 < a[i].first) {
            ans += pq.top();
            pq.pop();
            c++;
        }
    }

    printf("%d\n", ans);
}