#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <tuple>
#include <algorithm>
#include <cmath>
#include <string>
#include <climits>
using namespace std;
int N;
bool cnt[2000001] = {0,};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        cnt[t+1000000]=true;
    }
    for (int i = 0; i <= 2000000; i++)
    {
        if (cnt[i])
            cout << i-1000000 << '\n';
    }
}