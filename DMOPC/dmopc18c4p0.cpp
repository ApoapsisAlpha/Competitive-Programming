#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int r, x, y;
pair<int, pair<int, int> > stars[3];

int main() {
    scanf("%d %d %d", &r, &x, &y);
    for (int i = 0; i < 3; i++) {
        scanf("%d %d %d", &stars[i].second.first, &stars[i].second.second, &stars[i].first);
    }

    sort(stars, stars+3);
    int a = stars[0].second.first;
    int b = stars[0].second.second;
    if ((y-b)*(y-b)+(x-a)*(x-a) < r*r) printf("What a beauty!");
    else printf("Time to move my telescope!");
}