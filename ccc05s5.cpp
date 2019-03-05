#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, arr[100001], arr2[100001];
map<int, int> m;
ll ans;
ll tree[100001];

void update(int i) {
    while (i <= n) {
        tree[i]++;
        i += i & (-i);
    }
}

int query(int i) {
    int sum = 0;
    while (i > 0) {
        sum += tree[i];
        i -= i & (-i);
    }

    return sum;
}


int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
        arr2[i] = arr[i];
    }
    sort(arr2, arr2+n+1);
    for (int i = 1; i <= n; i++) {
        m[arr2[i]] = i;
    }

    for(int i = 1; i <= n; i++) {
        ans += query(n) - query(m[arr[i]])+1;
        update(m[arr[i]]);
    }

    printf("%.2f\n", ans/(double)n);
}