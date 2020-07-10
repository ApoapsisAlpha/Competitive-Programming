#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n, x;
pii a[200005];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        a[i] = make_pair(v, i+1);
    }
    sort(a, a+n);

    int i = 0;
    int j = n-1;
    while (i < j) {
        if (a[i].first+a[j].first == x) break;
        else if (a[i].first+a[j].first < x) i++;
        else j--;
    }

    if (i == j) cout << "IMPOSSIBLE\n";
    else cout << a[i].second << " " << a[j].second << "\n";
}

