#include <cstdio>
#include <vector>

std::vector<int> arr[3];
int counters[3];

void pop(int m) {
	printf("%d ", arr[m].back());
	arr[m].pop_back();
    counters[m]--;
}

int main() {
    int n;
    scanf("%d", &n);

    int x;

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        counters[x%3]++;
        arr[x%3].push_back(x);
    }

    if (counters[1] && !counters[0] && !counters[2]){
        while (counters[1]) pop(1);
        return 0;
    }
    if (counters[2] && !counters[0] && !counters[1]){
        while (counters[2]) pop(2);
        return 0;
    }
        

    if (!counters[0] || (counters[0]-1 > counters[1] + counters[2])) {
        printf("impossible");
        return 0;
    }

    if (counters[0] == 1) {
        while (counters[1]) pop(1);
        pop(0);
        while (counters[2]) pop(2);
        return 0;
    }
    else {
        pop(0);
        if (counters[1]) {
            for (int i = 0; counters[1] && counters[0] > 1; i++) {
                if (i%2) {
                    pop(0);
                }
                else {
                    pop(1);
                }
            }
            while (counters[1]) pop(1);
            pop(0);
        }
        for (int i = 0; counters[2] && counters[0]; i++) {
            if (i%2) {
                pop(0);
            }
            else {
                pop(2);
            }
        }
        while (counters[2]) pop(2);
        if (counters[0]) pop(0);
    }

}