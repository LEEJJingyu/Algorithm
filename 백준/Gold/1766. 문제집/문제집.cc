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
vector<int> arr[32001];
int cnt[32001];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	while (M--)
	{
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		cnt[b]++;
	}
	priority_queue<int,vector<int>,greater<int>> q;
	for (int i = 1; i <= N; i++)
		if(cnt[i]==0)q.push(i);
	while (!q.empty())
	{
		int cur = q.top(); q.pop();
		cout << cur << ' ';
		for (int nxt : arr[cur])
		{
			cnt[nxt]--;
			if (cnt[nxt] == 0)
				q.push(nxt);
		}
	}
}

