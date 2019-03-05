#include <bits/stdc++.h>

using namespace std;

void replace_all(string& data, string toSearch, string replaceStr)
{
	size_t pos = data.find(toSearch);
 
	while(pos != string::npos)
	{
		data.replace(pos, toSearch.size(), replaceStr);
		pos = data.find(toSearch, pos + toSearch.size());
	}
}

string solve(string word) {
    while(word.find("ANA") != string::npos || word.find("BAS") != string::npos) {
        replace_all(word, "ANA", "A");
        replace_all(word, "BAS", "A");
    }
    
    if (word == "A") return "YES";
    else return "NO";
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    while(1) {
        string x;
        cin >> x;
        if (x == "X") break;
        cout << solve(x) << "\n";
    }
}