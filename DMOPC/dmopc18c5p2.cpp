#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
double a[1001][1001], avg, tot;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            tot += a[i][j];
        }
    }

    avg = tot/(n*m);
    if (abs(0.48-avg) <= 0.000000001) {
        cout << "correctly exposed\n";
    }
    else if (avg > 0.48) {
        cout << "overexposed\n";
        cout << 0.48/avg;
    }
    else {
        cout << "underexposed\n";
        double x = 0.48/avg;
        double c = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j]*x > 1) {
                    tot -= a[i][j];
                    c++;
                }
            }
        }

        cout << (0.48*m*n-c)/tot;
    }
}