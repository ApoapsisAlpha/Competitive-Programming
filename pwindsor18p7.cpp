#include <bits/stdc++.h>

using namespace std;

vector<string> nums;

int cmp(string x, string y) 
{ 
    string a = x.append(y); 
    string b = y.append(x); 
    return a.compare(b) > 0 ? 1 : 0; 
} 

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.push_back(to_string(x));
    }

    sort(nums.begin(), nums.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << nums[i];
    }
    
}