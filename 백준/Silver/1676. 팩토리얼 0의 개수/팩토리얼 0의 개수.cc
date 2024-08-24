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
int N;
pair<int, int> num[501];
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    num[1] = { 0,0 };
    for (int i = 2; i <= N; i++)
    {
        int n = i;
        num[i] = num[i - 1];
        while (n % 2 == 0)
        {
            n /= 2;
            num[i].first++;
        }
        while (n % 5 == 0)
        {
            n /= 5;
            num[i].second++;
        }
    }
    cout << min(num[N].first, num[N].second);
}