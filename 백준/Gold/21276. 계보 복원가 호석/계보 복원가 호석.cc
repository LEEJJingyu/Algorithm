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

int N,M;
map<string, int> m;
string arr[1000];
vector<int> und[1000];
int cnt[1000] = {0};
int deg[1000] = {0};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		m[arr[i]] = i;
	}
	cin >> M;
	while (M--)
	{
		string a, b;
		cin >> a >> b;
		int na = m[a];
		int nb = m[b];
		und[nb].push_back(na);
		cnt[na]++;
		deg[nb]++;
	}
	pair<int,set<string>> ans;
	
	for (int i = 0; i < N; i++)
	{
		if (cnt[i] == 0)
		{
			ans.first++;
			ans.second.insert(arr[i]);
		}
	}
	cout << ans.first << '\n';
	for (string	 i : ans.second)
		cout << i << ' ';
	cout << '\n';
	for (auto cur : m)
	{
		cout << cur.first << ' ';
		set<string> tmp;
		for (int i : und[cur.second]) {
			if (cnt[cur.second] + 1 == cnt[i])
				tmp.insert(arr[i]);
		}
		cout << tmp.size()<<' ';
		for (string i : tmp)
			cout << i << ' ';
		cout << '\n';
	}
}

