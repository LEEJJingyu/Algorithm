#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <tuple>
#include <queue>
#include <cmath>
#include <set>
#include<ctime>
#include<stack>
#include <algorithm>
using namespace std;

int N, M;
vector<int> arr[1001];
int cnt[1001] = {0};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	while (M--)
	{
		int n;
		cin >> n;
		vector<int> tmp(n);
		for (int i = 0; i < n; i++)
		{
			int t;
			cin >> t;
			cnt[t] += i;
			tmp[i] = t;
		}
		for (int i = 0; i < n-1; i++)
		{
			for (int j = i + 1; j < n; j++)
				arr[tmp[i]].push_back(tmp[j]);
		}
	}
	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (cnt[i] == 0)
			q.push(i);
	vector<int> ans;
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		ans.push_back(cur);
		for (int nxt : arr[cur])
		{
			cnt[nxt]--;
			if (cnt[nxt] == 0)
				q.push(nxt);
		}
	}
	if (ans.size() == N)
		for (int i : ans)
			cout << i << '\n';
	else
		cout << 0;
}

