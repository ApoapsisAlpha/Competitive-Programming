#include <bits/stdc++.h>
#define ll long long

using namespace std;

unordered_map<int, ll> memo;

ll solve(int n) {
    if (memo.count(n)) return memo[n];
    ll ans = 0;
    int i = 1;
    int b = n;
    while (i < n) {
        int c = n/i - n/(i+1);
        ans += solve(i) * c;
        b -= c;
        i = n / b;
    }

    memo[n] = ans;
    return memo[n];
}

int main() {
    int n;
    scanf("%d", &n);
    memo[1] = 1;
    memo[2] = 1;

    printf("%lld", solve(n));
}