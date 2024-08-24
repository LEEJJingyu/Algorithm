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
int T;

int func(int a, int b)
{
    if (a == 0)return b;
    return func(b % a, a);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        long long a, b;
        cin >> a >> b;
        long long gcd = func(a, b);
        cout << b / gcd * a<< '\n';
    }
}