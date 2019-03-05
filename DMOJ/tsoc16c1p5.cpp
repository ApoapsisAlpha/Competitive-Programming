#include <cstdio>
#include <vector>

using namespace std;

long long qi[100];
long long factorials[20];

vector<int> solve(int n, long long q) {
    vector<int> p;
    vector<int> s;
    for (int i = 0; i < n; ++i) {
        s.push_back(i+1);
    }

    for (; n > 0; --n) {
        int x = q / factorials[n-1];
        p.push_back(s[x]);
        s.erase(s.begin() + x);
        q %= factorials[n-1];
    }

    return p;
}

void fact(int n) {
    factorials[0] = 1;
    for (int i = 1; i <= n; ++i) {
        factorials[i] = i * factorials[i-1];
    }
}

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    fact(n);
    
    for (int i = 0; i < q; ++i) {
        scanf("%lld", &qi[i]);
    }

    for (int i = 0; i < q; ++i) {
        for (int i : solve(n, qi[i])) {
            printf("%d ", i);
        }
        printf("\n");
    }
}