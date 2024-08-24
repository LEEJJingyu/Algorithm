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
long long n, m, two, five;
long long func(long long num, int p) {
    long long rtn = 0, div = p;
    while (num / div) {
        rtn += (num / div);
        div *= p;
    }
    return rtn;
}
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    two = func(n, 2) - func(m, 2) - func((n - m), 2);
    five = func(n, 5) - func(m, 5) - func((n - m), 5);
    cout << min(two, five);
}