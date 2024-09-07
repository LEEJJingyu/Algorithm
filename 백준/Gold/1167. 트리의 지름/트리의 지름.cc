#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <tuple>
#include <queue>
#include <cmath>
#include <set>
#include<ctime>
#include <algorithm>
using namespace std;

int n;
vector<pair<int,int>> arr[100001];
pair<int, int> len[100001];

void func(int cur, int pre)
{
	for (auto nxt : arr[cur])
	{
		if (pre != nxt.second)
		{
			func(nxt.second, cur);
			int val = max(len[nxt.second].first, len[nxt.second].second);
			if (len[cur].first > len[cur].second)
				swap(len[cur].first, len[cur].second);
			if (len[cur].first < val + nxt.first)
			{
				len[cur].first = val + nxt.first;
			}
			else if(len[cur].second < val + nxt.first)
			{
				len[cur].second = val + nxt.first;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		len[i] = { 0,0 };
	for (int i = 0; i < n; i++)
	{
		int cur;
		cin >> cur;
		while (true)
		{
		int u, cost;
		cin >> u;
		if (u == -1)break;
		cin >> cost;
		arr[cur].push_back({ cost,u });

		}
	}
	func(1, 0);
	int mx = 0;
	for (int i = 1; i <= n; i++)
	{

		mx = max(mx, len[i].first + len[i].second);
	}
	cout << mx;

}
