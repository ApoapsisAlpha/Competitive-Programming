#include <bits/stdc++.h>
using namespace std;

int n, x, y, z;

int main() {
    for (int t = 0; t < 10; t++) {
        cin >> n >> x >> y >> z;
        vector<string> codes(n);
        vector<int> mis;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            string code = "";
            for (int j = 0; j < s.size(); j++) {
                int num = s[j]-'0';
                if (num == 0) {
                    code += to_string(z);
                }
                else if (num % 2) {
                    code += to_string(max(0, num-y));
                }
                else {
                    code += to_string(num+x);
                }
            }

            codes[i] = code;
        }

        char a;
        cin >> a;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            if (s != codes[i]) mis.push_back(i+1);
        }

        char enda;
        cin >> enda;

        if (mis.size()) {
            cout << "FAIL: ";
            for (int i = 0; i < mis.size(); i++) {
                cout << mis[i];
                if (i < mis.size()-1) cout << ",";
            }
        }
        else {
            cout << "MATCH";
        }

        cout << '\n';
    }
}
