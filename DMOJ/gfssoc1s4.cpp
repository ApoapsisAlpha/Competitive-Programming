#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

char c;
int n, q;
ll ans;
int arr[251][251][251];
ll tree[251][251][251];

void update(int x, int y, int z, int v) {
    int y1, z1;
    while (x <= n) {
        y1 = y;
        while (y1 <= n) {
            z1 = z;
            while (z1 <= n) {
                tree[x][y1][z1] += v;
                z1 += (z1 & -z1);
            }
            y1 += (y1 & -y1);
        }
        x += (x & -x);
    }
}

ll query(int x, int y, int z) {
    ll sum = 0;
    int y1, z1;
    while (x > 0) {
        y1 = y;
        while (y1 > 0) {
            z1 = z;
            while (z1 > 0) {
                sum += tree[x][y1][z1];
                z1 -= (z1 & -z1);
            }
            y1 -= (y1 & -y1);
        }
        x -= (x & -x);
    }

    return sum;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> q;

    while (q--) {
        cin >> c;
        if (c == 'C') {
            int x, y, z, v;
            cin >> x >> y >> z >> v;
            update(x, y, z, v-arr[x][y][z]);
            arr[x][y][z] = v;
        }
        else if (c == 'S') {
            int x1, y1, z1, x2, y2, z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            ans += query(x2, y2, z2) - query(x1-1, y2, z2)  - query(x2 , y1-1, z2) + query(x1-1,y1-1, z2);
            ans -= query(x2, y2, z1-1) - query(x1-1, y2, z1-1) - query(x2, y1-1, z1-1)  + query(x1-1, y1-1, z1-1);
        }
    }

    cout << ans << '\n';
}