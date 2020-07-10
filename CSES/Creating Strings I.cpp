
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

string s;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    sort(s.begin(), s.end());
    vector<string> p;
    p.push_back(s);
    while(next_permutation(s.begin(), s.end())) p.push_back(s);
    cout << p.size() << "\n";
    for (int i = 0; i < p.size(); i++) cout << p[i] << "\n";
}
