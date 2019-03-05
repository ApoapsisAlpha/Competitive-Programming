#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll q, k, x, y;
vector<ll> vec;

int main() {
    scanf("%lld %lld", &q, &k);
    for (int i = 0; i <= 1000000; i++) {
        string s1 = to_string(i), s2 = s1, s = "";
        reverse(s2.begin(), s2.end());
        s = s1 + s2;
        ll t = stoll(s);
        if (t % k == 0) vec.push_back(t);
        s1.pop_back();
        s = s1 + s2;
        t = stoll(s);
        if (t % k == 0) vec.push_back(t);
    }
    
    sort(vec.begin(), vec.end());
    for (int i = 1; i <= q; i++) {
        scanf("%lld %lld", &x, &y);
        printf("%d\n", upper_bound(vec.begin(), vec.end(), y) - lower_bound(vec.begin(), vec.end(), x));
    }
}