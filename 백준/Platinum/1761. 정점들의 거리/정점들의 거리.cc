#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int N;
int M;
vector<pair<int, int>> arr[40001];
pair<int, int> parent[40001];
int depth[40001] = { 0 };
void dfs(int cur, int par)
{
	for (auto nxt : arr[cur])
	{
		if (nxt.second != par) {
			depth[nxt.second] = depth[cur] + 1;
			parent[nxt.second] = { nxt.first,cur };
			dfs(nxt.second, cur);
		}
	}
}
int lca(int a, int b)
{
	if (depth[a] < depth[b])
		swap(a, b);
	int  aD = 0;;
	while (depth[a] != depth[b]) {
		aD += parent[a].first;
		a = parent[a].second;
	}
	if (a == b)
		return aD;
	int bD = 0;
	while (a != b)
	{
		aD += parent[a].first;
		a = parent[a].second;
		bD += parent[b].first;
		b = parent[b].second;
	}
	return aD + bD;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int u, v, cost;
		cin >> u >> v >> cost;
		arr[u].push_back({ cost,v });
		arr[v].push_back({ cost,u });
	}
	parent[1] = { 0,0 };
	dfs(1, 0);

	cin >> M;
	while (M--)
	{
		int u, v;
		cin >> u >> v;
		cout << lca(u, v) << '\n';
	}

}