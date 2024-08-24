#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<stack>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<tuple>
using namespace std;
string s;
int num = 0;
int arr[10] = { 0, };
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    for (char c : s)
    {
        num += c - '0';
        arr[c - '0']++;
    }
    if (arr[0]==0 || num % 3 != 0)
    {
        cout << -1;
        return 0;
    }
    for (int i = 9; i >=0; i--)
    {
        while (arr[i]--)
        {
            cout << i;
        }
    }
}