#include<bits/stdc++.h>

using namespace std;

int n;
string a, b;

bool isSmaller(string& str1, string& str2)
{
    int n1 = str1.length(), n2 = str2.length();
 
    if (n1 < n2) return true;
    if (n2 < n1) return false;
 
    for (int i= n1-1; i >= 0; i--)
       if (str1[i] < str2[i]) return true;
       else if (str1[i] > str2[i]) return false;
 
    return false;
}

string findSum(string str1, string str2)
{
    if (str1.length( )< str2.length()) swap(str1, str2);
    string str;
 
    int n1 = str1.length(), n2 = str2.length();
    bool neg1 = false;
    bool neg2 = false;
    if (str1[0] == '-') neg1 = true;
    if (str2[0] == '-') neg2 = true;

    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;

    if ((!neg1 && !neg2) || (neg1 && neg2)) {
        if (neg1 && neg2) {
            str1.pop_back();
            str2.pop_back();
            n1--; n2--;
        }
        for (int i = 0; i < n2; i++) {
            int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
            str.push_back(sum%10 + '0');
            carry = sum/10;
        }
     
        for (int i = n2; i < n1; i++) {
            int sum = ((str1[i]-'0')+carry);
            str.push_back(sum%10 + '0');
            carry = sum/10;
        }

        if (carry)
            str.push_back(carry+'0');
        if (neg1 && neg2)
            str.push_back('-');
    }
    else {
        if (neg1) {
            str1.pop_back();
            n1--;
        }
        else if (neg2) {
            str2.pop_back();
            n2--;
        }

        bool s = false;
        if (isSmaller(str1, str2)) {
            swap(str1, str2);
            swap(n1, n2);
            s = true;
        }
        for (int i = 0; i < n2; i++) {
            int sub = ((str1[i]-'0')-(str2[i]-'0')-carry);
     
            if (sub < 0) {
                sub += 10;
                carry = 1;
            }
            else carry = 0;
            str.push_back(sub + '0');
        }

        for (int i = n2; i < n1; i++) {
            int sub = ((str1[i]-'0') - carry);
            if (sub < 0) {
                sub += 10;
                carry = 1;
            }
            else carry = 0;
            str.push_back(sub + '0');
        }
        while (str.size()>1 && str.back()=='0') str.pop_back();
        if (!(str.size() == 1 && str[0] == '0') && ((neg2 && s) || (neg1 && !s)))
            str.push_back('-');
    }

    reverse(str.begin(), str.end());
    return str;
}
 
int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << findSum(a, b) <<"\n";
    }
    return 0;
}