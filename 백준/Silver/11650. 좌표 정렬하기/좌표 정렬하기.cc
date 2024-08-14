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
#include <map>

using namespace std;
int N;
vector<pair<int, int>> pos;
int cnt[1000000] = { 0, };
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        pos.push_back({ x, y });
    }
    sort(pos.begin(), pos.end());
    for (int i = 0; i < N; i++)
    {
        cout << pos[i].first << ' ' << pos[i].second<<'\n';
    }

}