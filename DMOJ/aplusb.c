#include <stdio.h>

int main() {
    int N;
    scanf("%d\n", &N);

    for (int i = 0; i < N; i++) {
        int a, b;
        scanf("%d %d\n", &a, &b);
        printf("%d\n", a + b);
    }
}