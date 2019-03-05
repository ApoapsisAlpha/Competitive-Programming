#include <cstdio>
const float area = 31250;

int main() {
    int x, y;
    scanf("%d %d", &x, &y);

    float t;

    if (x >= 125 && y == 0) {
        t = area/x;
        printf("%.2f %.2f", 0.00, t);
    }
    else if (x <= 125 && y == 0) {
        t = area/(250-x);
        printf("%.2f %.2f", 250-t, t);
    }
    else if (x == 0 && y >= 125) {
        t = area/y;
        printf("%.2f %.2f", t, 0.00);
    }
    else if (x == 0 && y <= 125) {
        t = area/(250-y);
        printf("%.2f %.2f", t, 250-t);
    }
    else if (x >= 125 && y <= 125) {
        t = area/x;
        printf("%.2f %.2f", 0.00, 250-t);
    }
    else if (x <= 125 && y >= 125) {
        t = area/y;
        printf("%.2f %.2f", 250-t, 0.00);
    }

}