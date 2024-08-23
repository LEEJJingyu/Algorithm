#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<cmath>
#include<vector>
using namespace std;
string s;
char pre = ' ';
int cnt = 0;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s;
    for(char c : s)
    {
        if (pre != c)
        {
            pre = c;
            cnt++;
        }
    }
    cout << cnt / 2;
}
