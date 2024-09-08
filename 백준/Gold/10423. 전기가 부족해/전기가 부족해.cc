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


int N, M, K;
bool chk[1001] = { 0 };
vector<pair<int,int>> arr[1001];
vector<int> powerStation;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < K; i++)
    {
        int t;
        cin >> t;
        powerStation.push_back(t);
        chk[t] = true;
    }
    for (int i = 0; i < M; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        arr[u].push_back({ cost,v });
        arr[v].push_back({ cost,u });
    }
    for (int num : powerStation)
    {
        for (auto nxt : arr[num])
        {
            if (!chk[nxt.second])
                pq.push({ nxt.first,nxt.second });
        }
    }
    int cnt = K-1;
    int sum = 0;
    while (!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if (chk[cur.second])continue;
        chk[cur.second] = true;
        sum += cur.first;
        cnt++;
        for(auto nxt : arr[cur.second])
            if (!chk[nxt.second])
                pq.push({ nxt.first,nxt.second });
        if (cnt == N - 1)break;
    }
    cout << sum << '\n';
}