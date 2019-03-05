#include <bits/stdc++.h>

using namespace std;

int main() {
    int w, h;
    scanf("%d%d", &w, &h);
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (i % 2) {
                if (j % 2) {
                    printf("0");
                }
                else {
                    printf("1");
                }
            }
            else {
                if (j % 2) {
                    printf("1");
                }
                else {
                    printf("0");
                }
            }
        }
        printf("\n");
    }
}