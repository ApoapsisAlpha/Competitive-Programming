#include <bits/stdc++.h>
using namespace std;

string s;
float ra, ga, ba, rb, gb, bb;

int main() {
    cin >> s;
    cin >> ra >> ga >> ba;
    cin >> rb >> gb >> bb;
    if (s == "Multiply") {
        cout << ra*rb << " " << ga*gb << " " << ba*bb;
    }
    else if (s == "Screen") {
        cout << 1-(1-ra)*(1-rb) << " " << 1-(1-ga)*(1-gb) << " " << 1-(1-ba)*(1-bb);
    }
    else {
        float a = ra < 0.5 ? 2*ra*rb : 1-2*(1-ra)*(1-rb);
        float b = ga < 0.5 ? 2*ga*gb : 1-2*(1-ga)*(1-gb);
        float c = ba < 0.5 ? 2*ba*bb : 1-2*(1-ba)*(1-bb);
        cout << a << " " << b << " " << c;
    }
}