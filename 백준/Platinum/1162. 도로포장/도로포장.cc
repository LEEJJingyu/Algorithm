#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

int N, M, K;
priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>>pq;
vector<tuple<long long,int, int>> arr[10001];

long long d[10001][21];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < M; i++)
	{
		int u, v;
		long long cost;
		cin >> u >> v >> cost;
		arr[u].push_back({ cost,v,0 });
		arr[v].push_back({ cost,u,0 });
		arr[u].push_back({ 0,v,1 });
		arr[v].push_back({ 0,u,1 });
	}
	pq.push({ 0,1,0 });
	for (int i = 2; i <= N; i++)
		fill(d[i], d[i] + K + 1, 1e12);
	fill(d[1], d[1] + K + 1, 0);
	while (!pq.empty()) {
		long long cost; int s, k;
		tie(cost, s, k) = pq.top(); pq.pop();
		if (d[s][k] != cost)continue;
		for (auto nxt : arr[s])
		{
			long long nc; int ns, nk;
			tie(nc, ns, nk) = nxt;
			nc += cost;
			nk += k;
			if (nk > K)continue;
			if (nc >= d[ns][nk])continue;
			d[ns][nk] = nc;
			pq.push({nc,ns,nk});
		}
	}
	long long mn = 1e12;
	for (int i = 0; i <= K; i++)
		mn = min(mn, d[N][i]);
	cout << mn;
}
