#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
int main() {
    cin>>a>>b>>c>>d;
    if ((a==9||a==8)&&(d==8||d==9)&&(b==c))
        cout<<"ignore";
    else cout<<"answer";
}