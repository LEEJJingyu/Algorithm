#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <tuple>
#include <queue>
#include <cmath>
#include <set>
#include<map>
#include<stack>
#include <algorithm>
using namespace std;

int N, M;
vector<pair<int, int>> arr[101];
int cnt[101] = { 0 };
int deg[101] = { 0 };
bool isNotAns[101] = { 0 };
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int x, y, k;
		cin >> x >> y >> k;
		arr[x].push_back({ y,k });
		deg[y]++;
		isNotAns[x] = true;
	}
	cnt[N] = 1;
	queue<int> q;
	q.push(N);
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (auto sub : arr[cur])
		{
			deg[sub.first]--;
			cnt[sub.first] += sub.second * cnt[cur];
			if (!deg[sub.first])
				q.push(sub.first);
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (!isNotAns[i])
			cout << i << ' ' << cnt[i] << '\n';
	}
}
