#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    while (n--) {
        int t;
        scanf("%d", &t);

        int count = 0;
        int ud = t;
        int ol = 0;
        int el = 0;
        
        while (true) {
            printf("Round %d: %d undefeated, %d one-loss, %d eliminated\n", count, ud, ol, el);
            if (ud == 0 && ol == 1) break;
            if (ud == 1 && ol == 1) {
                ud = 0;
                ol = 2;
            }
            else {
                el += ol/2;
                ol = ol - ol/2 + ud/2;
                ud -= ud/2;
            }
            
            count++;
        }

        printf("There are %d rounds.\n\n", count);
    }
}