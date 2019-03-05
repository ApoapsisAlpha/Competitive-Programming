#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    
    int k = 0;
    while(n > 0) {
        k++;
        n -= 9 * pow(10, k - 1) * k;
    }
    n += 9 * pow(10, k - 1) * k;
    if(n % k == 0) {
        int fn = pow(10, k - 1) + (n / k) - 1;
        printf("%d", fn % 10);
        return 0;
    }
    else {
        int fn = pow(10, k - 1) + (n / k);
        printf("%d", static_cast<int>((fn / pow(10, k - (n % k)))) % 10);
        return 0;
    }
}