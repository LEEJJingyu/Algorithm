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
int cnt[10000] = {0,};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        cnt[t-1]++;
    }
    for (int i = 0; i < 10000; i++)
    {
        while(cnt[i]--)
            cout << i+1 << '\n';
    }
}