#include <bits/stdc++.h>
using namespace std;

int n, x, y;
vector<int> adj[10001];
int dp[10001];

int main() {
    cin >> n;
    cin >> x >> y;
    while (x && y) {
        adj[x].push_back(y);
        cin >> x >> y;
    }   

    dp[1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int u : adj[i]) dp[u] += dp[i];
    }
    cout << dp[n];
}