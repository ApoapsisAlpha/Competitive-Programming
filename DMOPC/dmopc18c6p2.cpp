#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

string a[4];
string b[4];
string a2[4];
string b2[4];

bool check() {
    for (int i = 0; i < 4; i++) {
        if (a[i] != b[i]) return false;
    }

    return true;
}

void rot(int skip) {
    int cur = (skip+1)%4;
    string tmp = b[cur];
    cur = (cur+1)%4;
    while (cur != skip) {
        string t = b[cur];
        b[cur] = tmp;
        tmp = t;
        cur = (cur+1)%4;
    }

    b[(skip+1)%4] = tmp;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < 4; i++) {
        cin >> a[i];
        a2[i] = a[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> b[i];
        b2[i] = b[i];
    }

    sort(a2, a2+4);
    sort(b2, b2+4);
    for (int i = 0; i < 4; i++) {
        if (a2[i] != b2[i]) {
            cout << "NO\n";
            return 0;
        }
    }

    for (int k = 0; k < 4; k++) {
        for (int j = 0; j < 4; j++) {
            rot(k);
            for (int i = 0; i < 3; i++) {
                rot(j);
                if (check()) {
                    cout << "NO\n";
                    return 0;
                }
            }
        }
    }

    cout << "YES\n";
}
