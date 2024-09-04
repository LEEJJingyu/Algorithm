#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <list>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;

int N;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	int ans = 0, cnt = 0;
	vector<vector<pair<int, int>>> cnnC(N+1, vector<pair<int, int>>(N+1));
	for (int i = 1; i <= N; i++)
	{
		int cost;
		cin >>cost;
		cnnC[i].push_back({ cost,0 });
		cnnC[0].push_back({ cost,i });
	}
	vector<bool> chk(N+1, 0);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
		{
			int cost;
			cin >> cost;
			cnnC[i].push_back({ cost,j });
		}
	}
	priority_queue < tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
	chk[0] = true;
	for (auto imp : cnnC[0])
	{
		if (!chk[imp.second]) {
			pq.push({ imp.first,0,imp.second });
		}
	}

	while (cnt < N)
	{
		int cost, a, b;
		tie(cost, a, b) = pq.top(); pq.pop();
		if (chk[b])continue;
		ans += cost;
		chk[b] = true;
		cnt++;
		for (auto nxt : cnnC[b])
		{
			if (!chk[nxt.second])
			{
				pq.push({ nxt.first,b,nxt.second });
			}
		}
	}

	cout << ans;

}