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
int N, a, b;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> a >> b;
    
    a--;
    b--;
    int result = a ^ b;
    int cnt = 0;
    while (result)
    {
        cnt++;
        result=(result>>1);

    }
    cout << cnt << '\n';
}