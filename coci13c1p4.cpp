#include <cstdio>
#include <set>
#include <algorithm>

std::pair<int, int> items[300000];

bool cmp(const std::pair<int, int>& a, const std::pair<int, int>& b) {
	if (a.second != b.second)
        return a.second > b.second;
	return a.first < b.first;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].first, &items[i].second);
    }

    std::sort(items, items + n, cmp);

    std::multiset<int> bags;
    int x;
    for (int i = 0; i < k; i++) {
        scanf("%d", &x);
        bags.insert(x);
    }

    long long tot = 0;
    for (int i = 0; i < n; i++) {
        if (bags.empty()) break;
        std::multiset<int>::iterator bag = bags.lower_bound(items[i].first);
        if (bag != bags.end()) {
            tot += items[i].second;
            bags.erase(bag);
        }
    }

    printf("%lld", tot);
}