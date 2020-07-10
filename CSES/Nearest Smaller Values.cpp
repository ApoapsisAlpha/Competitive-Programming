#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int n;
int a[200005];
stack<int> s;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        while (!s.empty() && a[i] <= a[s.top()-1]) s.pop();
        if (s.empty()) cout << "0 ";
        else cout << s.top() << " ";
        s.push(i+1);
    }
}
