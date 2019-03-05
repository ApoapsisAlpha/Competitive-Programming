#include <bits/stdc++.h>
using namespace std;

int n, mx, numh;
int freq[2001];
int lengths[4001];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        freq[x]++;
    }
    
    for (int i = 1; i <= 2000; i++) {
        if (freq[i]) {
            for (int j = i; j <= 2000; j++) {
                if (i == j) lengths[i<<1] += freq[i]>>1;
                else if (freq[j]) {
                    lengths[i+j] += min(freq[i], freq[j]);
                }
            }
        }
    }
    
    for (int i = 2; i <= 4000; i++) {
        if (lengths[i] > mx) {
            mx = lengths[i];
            numh = 1;
        }
        else if (lengths[i] == mx) {
            numh++;
        }
    }
    
    printf("%d %d\n", mx, numh);
}