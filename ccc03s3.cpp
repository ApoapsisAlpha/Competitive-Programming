#include <bits/stdc++.h>
using namespace std;

int k, r, c, area, numrooms;
int grid[26][26];
vector<int> rooms;

void flood(int i, int j) {
    if (i < 0 || i >= r || j < 0 || j >= c) return;
    if (grid[i][j] == -1) return;
    area++;
    grid[i][j] = -1;
    flood(i+1, j);
    flood(i, j+1);
    flood(i-1, j);
    flood(i, j-1);
}

int main() {
    cin >> k;
    cin >> r;
    cin >> c;
    for (int i = 0; i < r; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < c; j++) {
            if (line[j] == 'I')
                grid[i][j] = -1;
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (grid[i][j] == -1) continue;
            area = 0;
            flood(i, j);
            rooms.push_back(area);
        }
    }

    sort(rooms.begin(), rooms.end(), greater<int>());

    for (int i : rooms) {
        if (k-i < 0) break;
        k -= i;
        numrooms++;
    }

    if (numrooms == 1) {
        cout << numrooms << " room, " << k << " square metre(s) left over";
    }
    else {
        cout << numrooms << " rooms, " << k << " square metre(s) left over";
    }
}