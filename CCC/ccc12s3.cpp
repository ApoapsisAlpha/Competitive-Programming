#include <bits/stdc++.h>

using namespace std;

int n;
int f[1001];
int bf;
int sb;
vector<int> best;
vector<int> sbest;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int r;
        scanf("%d", &r);
        f[r]++;
    }

    for (int i = 1; i <= 1000; i++) {
        if (f[i] > bf) {
            sb = bf;
            bf = f[i];
        }
        else if (f[i] < bf && f[i] > sb) {
            sb = f[i];
        }
    }

    for (int i = 1; i <= 1000; i++) {
        if (f[i] == bf) best.push_back(i);
        else if (f[i] == sb) sbest.push_back(i);
    }

    sort(best.begin(), best.end(), greater<int>());
    sort(sbest.begin(), sbest.end(), greater<int>());

    if (best.size() == 1 && sbest.size() == 1) {
        printf("%d\n", abs(best[0]-sbest[0]));
    }
    else if (best.size() > 1) {
        printf("%d\n", best[0]-best[best.size()-1]);
    }
    else if (best.size() == 1 && sbest.size() > 1) {
        printf("%d\n", max(abs(best[0]-sbest[sbest.size()-1]), abs(best[best.size()-1] - sbest[0])));
    }
    
}