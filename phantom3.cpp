#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int SQRT = 100001;
ll n, m;
int ans;
bool isprime[20000001];
vector<int> primes;

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;

    for (int i = 0; i < SQRT; i++) {
        isprime[i] = true;
    }
    
    for (int i = 2; i*i < SQRT; i++) {
        if (isprime[i]) {
            for (int j = i*i; j < SQRT; j += i) {
                isprime[j] = false;
            }
        }
    }

    primes.push_back(2);
    for (int i = 3; i < SQRT; i += 2) {
        if (isprime[i]) primes.push_back(i);
    }

    for (int i = 0; i < m-n; i++) {
        isprime[i] = true;
    }

    for (int i : primes) {
        if ((ll)i*i >= m) break;
        ll k = (n/i)*i;
        if (k < n) k += i;

        for (ll j = k; j < m; j += i) {
            isprime[j-n] = false;
        }

        if (k == i) isprime[k-n] = true;
    }


    for (int i = 0; i < m-n; i++) {
        if (isprime[i]) ans++;
    }

    printf("%d\n", ans);
}