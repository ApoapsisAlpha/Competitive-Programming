#include <bits/stdc++.h>

using namespace std;

int dis[100], vis[100];
vector<int> adj[100];

void dfs(int cur, int pre) {
    vis[cur] = 1;
    for (int v : adj[cur]) {
        if (vis[v] == 0){
            dis[v] = dis[cur] + 1;
            vis[v] = 1;
            dfs(v, cur);
        }
        else if (vis[v] == 1) 
            printf("%d\n", dis[cur] - dis[v] + 1);
    }
    vis[cur] = 2;
}

int main() {
    for (int i = 0, n; i < 5; i++) {
        scanf("%d", &n);
        for (int i = 0, a, b; i < n; i++){
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
        }
    
        dis[1] = 0;
        dfs(1, -1);
        for (int j = 0; j < 100; j++) {
            adj[j].clear();
            memset(dis, 0, sizeof(dis));
            memset(vis, 0, sizeof(vis));
        }
    }
    return 0;
}