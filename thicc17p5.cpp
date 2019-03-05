#include <bits/stdc++.h>

using namespace std;

int k;
long long n, ans, maxans;
unordered_map<int, int> s;
int a[1000001];
int l;

int main() {
    scanf("%lld %d", &n, &k);
    maxans = n*(n+1)/2;

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        s[a[i]]++;
        while (s.size() >= k && l < i) {
            if (s[a[l]] <= 1) {
                s.erase(a[l]);
            }
            else s[a[l]]--;
            l++;
        }

        if (s.size() < k) {
            ans += i-l+1;
        }
    }

    printf("%lld\n", maxans-ans);
}