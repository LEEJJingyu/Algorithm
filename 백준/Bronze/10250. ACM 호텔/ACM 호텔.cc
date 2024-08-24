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
int H, W, N;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while (T--)
    {
        cin >> H >> W >> N;
        if(N%H)
            cout << N % H;
        else
            cout << H;
        if ((N-1) / H > 8)
            cout << (N-1) / H+1;
        else
            cout << 0 << (N-1) / H+1;
        cout << '\n';
    }
}