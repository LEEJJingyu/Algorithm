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
vector<int> arr[100001];
int parent[100001] = {0};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	queue<int> q;
	q.push(1);
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (int node : arr[cur])
		{
			if (parent[cur] != node) {
				parent[node] = cur;
				q.push(node);
			}
		}
	}
	for (int i = 2; i <= N; i++)
		cout << parent[i] << '\n';
}