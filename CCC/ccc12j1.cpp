#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a, b;

int main() {
    scanf("%d %d", &a, &b);
    if (b-a <= 0) printf("Congratulations, you are within the speed limit!\n");
    else if (b-a <= 20) printf("You are speeding and your fine is $100.\n");
    else if (b-a <= 30) printf("You are speeding and your fine is $270.\n");
    else printf("You are speeding and your fine is $500.\n");
}