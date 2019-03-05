#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> Point;

struct Path {
    int a, b, d;
};

int n;
Point pts[2001];
vector<Path> paths;
int predist[2001], prebest[2001], best[2001];

int cmp(const Path &a, const Path &b) {
    return a.d < b.d;
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    pts[0].first = pts[0].second = 0;

    for (int i = 1; i <= n; i++) {
        cin >> pts[i].first >> pts[i].second;
    }

    for (int i = 0; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            Path p;
            p.a = i; p.b = j;
            int dx = pts[i].first - pts[j].first;
            int dy = pts[i].second - pts[j].second;
            p.d = dx*dx + dy*dy;
            paths.push_back(p);
        }
    }

    sort(paths.begin(), paths.end(), cmp);

    for (Path p : paths) {
        if (p.d != predist[p.a]) {
            predist[p.a] = p.d;
            prebest[p.a] = best[p.a];
        }
        if (p.d != predist[p.b]) {
            predist[p.b] = p.d;
            prebest[p.b] = best[p.b];
        }

        if (p.a == 0) {
            best[p.a] = max(best[p.a], prebest[p.b]);
        }
        else {
            best[p.a] = max(best[p.a], prebest[p.b]+1);
            best[p.b] = max(best[p.b], prebest[p.a]+1);
        }
    }

    cout << best[0]+1;
}