#include <bits/stdc++.h>

using namespace std;

int arr[500000];

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    long long m;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long sum = 0, len = n;
    int l = 0, r = 0;


    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    if (sum < m) cout << "-1";
    else {
        sum = 0;
        
        while (r < n) {
            while (sum <= m && r < n)
                sum += arr[r++];
            while (sum > m && l < n) {
                if (r-l < len)
                    len = r-l;
                sum -= arr[l++];
            }
        }

        cout << len;
    }
}