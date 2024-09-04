#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
#include <stack>
#include <map>
#include <unordered_set>
using namespace std;

vector<int> p(10001, -1);

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}

bool is_dif(int u, int v) {
	u = find(u); v = find(v);
	if (u == v) return 0;
	if (u <v) p[v] = u;
	else p[u] = v;
	return 1;
}
int V,E;
tuple<int, int, int> edge[100001];
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		int u, v, l;
		cin >> u >> v >> l;
		edge[i] = { l,u,v };
	}
	sort(edge, edge + E);
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < E; i++)
	{
		int cost, a, b;
		tie(cost, a, b) = edge[i];
		if (!is_dif(a, b))continue;
		sum += cost;
		cnt++;
		if (cnt == V - 1)break;
	}
	cout << sum;
}
