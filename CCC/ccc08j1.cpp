#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

double w, h;

int main() {
    scanf("%lf %lf", &w, &h);
    double bmi = w/(h*h);
    if (bmi < 18.5) printf("Underweight");
    else if (bmi <= 25) printf("Normal weight");
    else printf("Overweight");
}