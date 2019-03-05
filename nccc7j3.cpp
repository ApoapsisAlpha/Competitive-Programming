#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, k;

int main() {
    scanf("%lld %lld", &n, &k);
    ll c = n/(k+1);
    printf("%lld\n", n-c);
}