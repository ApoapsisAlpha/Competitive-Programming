#include <bits/stdc++.h>

using namespace std;

int n;
float md;
set<pair<float, float> > ans;

float dist(float x1, float y1, float x2, float y2) {
    float dx = x2-x1;
    float dy = y2-y1;
    return dx*dx+dy*dy;
}

int main() {
    scanf("%d", &n);
    vector<pair<float, float> > locs(n);
    
    for (int i = 0; i < n; i++) {
        scanf("%f %f", &locs[i].first, &locs[i].second);
    }
    
    for (float i = 0; i <= 1000.0; i += 0.01) {
        pair<float, float> tmp;
        md = 0x3f3f3f3f;
        for (auto j : locs) {
            float d = dist(j.first, j.second, i, 0);
            if (d < md) {
                md = d;
                tmp = j;
            }
        }
        
        ans.insert(tmp);
    }
    
    for (auto i : ans) {
        printf("The sheep at (%.2f, %.2f) might be eaten.\n", i.first, i.second);
    }
}