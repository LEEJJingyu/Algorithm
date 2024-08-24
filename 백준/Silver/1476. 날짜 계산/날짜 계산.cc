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
int E, S, M;
int ans = 1;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> E >> S >> M;
    int t = E;
    int gcd=15;
    while (t % 28 != S%28)
    {
        t += gcd;
    }
    gcd = 15 * 28;
    while (t % 19 != M % 19)
    {
        t += gcd;
    }
    cout << t << '\n';
}