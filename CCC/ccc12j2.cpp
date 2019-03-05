#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a[4];

int main() {
    bool rising = true;
    bool falling = true;
    bool same = true;
    for (int i = 0; i < 4; i++) {
        scanf("%d", &a[i]);
        if (i == 0) continue;
        if (a[i] > a[i-1]) {
            falling = false;
            same = false; 
        }
        else if (a[i] < a[i-1]) {
            rising = false;
            same = false;
        }
        else {
            rising = false;
            falling = false;
        }
    }
    
    if (rising) printf("Fish Rising");
    else if (falling) printf("Fish Diving");
    else if (same) printf("Fish At Constant Depth");
    else printf("No Fish");
    
}