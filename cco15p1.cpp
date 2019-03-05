#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, w;
vector<int> temps;

int min() {
    if (w > temps[0] && w < temps[n-1])
        return abs(temps[0] - w) + abs(temps[n-1] - w);
    else
        return (temps[n-1]-temps[0]) + min(abs(w - temps[0]), abs(w - temps[n-1]));
}

long long max() {
    long long tot1 = abs(w-temps[0]);
    long long tot2 = abs(w-temps[n-1]);
    int l = 1;
    int r = n-1;

    for (int i = 0; i < n-1; ++i) {
        if (i % 2) {
            tot1 += max(abs(temps[l] - w), temps[r+1] - temps[l]);
            l++;
        }
        else {
            tot1 += max(abs(temps[r] - w), temps[r] - temps[l-1]);
            r--;
        }
    }

    l = 0;
    r = n-2;

    for (int i = 0; i < n-1; ++i) {
        if (i % 2) {
            tot2 += max(abs(temps[r] - w), temps[r] - temps[l-1]);
            r--;
        }
        else {
            tot2 += max(abs(temps[l] - w), temps[r+1] - temps[l]);
            l++;
        }
    }

    return max(tot1, tot2);
}

int main() {
    scanf("%d %d", &n, &w);

    int t;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        temps.push_back(t);
    }

    sort(temps.begin(), temps.begin() + n);

    printf("%d %lld", min(), max());

}