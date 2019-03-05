#include <bits/stdc++.h>

using namespace std;

int main() {
    bool up = true;
    bool down = true;
    
    for (int i = 1; i < 8; i++) {
        int x;
        scanf("%d", &x);

        if (x != i) up = false;
        if (x != (9-i)) down = false;
    }
    
    if (up) printf("ascending");
    else if (down) printf("descending");
    else printf("mixed");
    
}