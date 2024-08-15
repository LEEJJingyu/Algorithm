#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <tuple>
#include <algorithm>
#include <cmath>
#include <string>
#include <climits>
using namespace std;
int N;
int population[10];
bool isred[10] = {0,};
int mn = 10000;
bool *visited;
vector<vector<int>> link(10);
queue<int> q;
int canLink(bool isblue)
{
    int st = 0;
    int ans = 0;
    visited = new bool[N]();
    for (int i = 0; i < N; i++)
    {
        if (isred[i] != isblue)
            st = i;
        else
            visited[i] = true;
    }
    q.push(st);
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if(!visited[cur])ans += population[cur];
        visited[cur] = true;
        for (int next : link[cur]) {
            if (!visited[next])
                q.push(next);
        }
    }
    for (int i = 0; i < N; i++)
        if (!visited[i]) {
            return 0;
        }
    return ans;
}

void func(int k)
{
    if (k == N)
    {
        int blue = canLink(true);
        if (!blue)return;
        int red = canLink(false);
        if (!red)return;
        if (mn > abs(blue - red))
            mn = abs(blue - red);
        return;
    }
    isred[k] = true;
    func(k + 1);
    isred[k] = false;
    func(k + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> population[i];
    }

    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        for (int j = 0; j < t; j++)
        {
            int n;
            cin >> n;
            link[i].push_back(n-1);
        }
    }
    isred[0] = true;
    func(1);
    if(mn==10000)mn=-1;
    cout << mn;
}