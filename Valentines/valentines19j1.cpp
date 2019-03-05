#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
    cin >> n;
    while(n--) {
        int x;
        cin >> x;
        if (x < 1000) cout << "Newbie";
        else if (x < 1200) cout << "Amateur";
        else if (x < 1500) cout << "Expert";
        else if (x < 1800) cout << "Candidate Master";
        else if (x < 2200) cout << "Master";
        else if (x < 3000) cout << "Grandmaster";
        else if (x < 4000) cout << "Target";
        else cout << "Rainbow Master";
        cout << '\n';
    }
}