#include <bits/stdc++.h>
using namespace std;

string s;
stack<int> st;
int c;

int main() {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (st.empty() && i != 0) {
            cout << "Invalid\n";
            return 0;
        }

        if (!st.empty()) c++;
        if (!st.empty() && c == s[st.top()]-'0') {
            st.pop();
            c = 0;
        }
        if (s[i] != '0') st.push(i);
    }

    if (st.empty()) cout << "Valid\n";
    else cout << "Invalid\n";
}