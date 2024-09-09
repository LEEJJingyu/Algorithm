#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

int N, M, K;
vector<pair<int, int>> arr[1001];
priority_queue<int> ans[1001];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++)
	{
		int u, v, c;
		cin >> u >> v >> c;
		arr[u].push_back({ c,v });
	}
		priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
		ans[1].push(0);
		pq.push({0,1});
		while (!pq.empty())
		{
			auto cur = pq.top(); pq.pop();
			for (auto nxt : arr[cur.second])
			{
				if (ans[nxt.second].size() < K)
				{
					ans[nxt.second].push(nxt.first+cur.first);
					pq.push({nxt.first+cur.first,nxt.second});
				}
				else if (ans[nxt.second].top() > nxt.first + cur.first)
				{
					ans[nxt.second].pop();
					ans[nxt.second].push(nxt.first+cur.first);
					pq.push({nxt.first+cur.first,nxt.second});
				}
			}
		}
	for (int i = 1; i <= N; i++)
	{
		if (ans[i].size() == K)
			cout << ans[i].top()<<'\n';
		else cout << -1 << '\n';
			
	}

}
