#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

unordered_map<ull, ull> memo;

ull fib(ull n) {
    if(n < 2) return 1;
    if(memo.find(n) != memo.end()) return memo[n];
    int ans = (fib((n+1)/2) * fib(n/2) + fib((n-1)/2) * fib((n-2)/2)) % 1000000007;;
    return memo[n] = ans;
}

int main() {
    ull n;
    scanf("%llu", &n);
    printf("%llu", fib(n-1));
}