#include <cstdio>
#include <algorithm>

using namespace std;

struct Ingredient {
    int x;
    int y;
    int sm;
    int pm;
    int sv;
    int pv;


    int cost(int n) {
        int cost = 1000000000;
        int i = 0;

        do {
            int small = max(((n*x - y)-i*sv+sm-1)/sm, 0);
            int newCost = small*pm + i*pv;
            cost = min(cost, newCost);
        } while ((i++ * sv) <= (n*x-y));

        return cost;
    }
};

Ingredient a[100];

bool isCostPossible(int m, int n, int k) {
    int tot = 0;

    for (int i = 0; i < n; i++) {
        tot += a[i].cost(k);
    }

    return tot <= m;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++) {
        scanf("%d %d %d %d %d %d", &a[i].x, &a[i].y, &a[i].sm, &a[i].pm, &a[i].sv, &a[i].pv);
    }

    
    int low = 0;
    int high = 1;
    while (isCostPossible(m, n, high)) high *= 2;

    while (low < high) {
        int mid = low + (high-low+1)/2;
        if (isCostPossible(m, n, mid)) low = mid;
        else high = mid - 1;
    }

    printf("%d", low);
}