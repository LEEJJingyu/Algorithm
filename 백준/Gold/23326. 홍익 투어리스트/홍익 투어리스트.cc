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
int N,Q;
set<int> univ;
int cur = 1;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++)
	{
		bool ch;
		cin >> ch;
		if (ch)
			univ.insert(i);
	}
	for (int i = 0; i < Q; i++)
	{
		int cmd;
		cin >> cmd;
		if (cmd == 1)
		{
			int t;
			cin >> t;
			auto itr = univ.find(t);
			if (itr != univ.end())
				univ.erase(itr);
			else
				univ.insert(t);
		}
		else if (cmd == 2)
		{
			int t;
			cin >> t;
			cur = (cur + t-1) % N+1;
		}
		else
		{
			if (univ.empty()) {
				cout << -1 << '\n';
			}
			else
			{
				auto dist = univ.lower_bound(cur);
				if (dist == univ.end())
				{
					dist = univ.lower_bound(0);
				}
				cout << (*dist-cur+N)%N << '\n';
			}
		}

	}
}