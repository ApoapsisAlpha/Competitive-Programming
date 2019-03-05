#include <bits/stdc++.h>

using namespace std;

int n, m, p, q;
vector<int> a[1000001];
bool visited[1000001];

bool bfs(int s, int d)
{
    list<int> q;
    
    visited[s] = true;
    q.push_back(s);
    
    while (!q.empty()) {
        s = q.front();
        q.pop_front();
        
        for (int i = 0; i < a[s].size(); i++) {
            if (a[s][i] == d) return true;
            
            if (!visited[a[s][i]]) {
                visited[a[s][i]] = true;
                q.push_back(a[s][i]);
            }
        }
    }
    
    return false;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        a[x].push_back(y);
    }

    scanf("%d %d", &p, &q);
    
    if (bfs(p, q)) printf("yes");
    else if (bfs(q, p)) printf("no");
    else printf("unknown");
}