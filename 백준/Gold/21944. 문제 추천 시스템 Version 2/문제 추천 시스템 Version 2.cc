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

int N, P;
map<int, set<pair<int, int>>> problemsByType;
set<pair<int, int>> problems;
pair<int,int> dict[100000];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int p, l, t;
		cin >> p >> l >> t;
		problemsByType[t].insert({ l,p });
		problems.insert({ l,p });
		dict[p] = { l,t };
	}
	cin >> P;
	for (int i = 0; i < P; i++)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "add")
		{
			int p, l, t;
			cin >> p >> l >> t;
			dict[p] = { l,t };
			problemsByType[t].insert({ l,p });
			problems.insert({ l,p });
		}
		else if (cmd == "solved")
		{
			int p;
			cin >> p;
			problems.erase({dict[p].first,p});
			problemsByType[dict[p].second].erase({dict[p].first,p});
		}
		else if (cmd == "recommend")
		{
			int x, t;
			cin >> t >> x;
			if (x == 1)
			{
				cout<<prev(problemsByType[t].end())->second<<'\n';
			}
			else
			{
				cout << problemsByType[t].begin()->second << '\n';
			}
		}
		else if (cmd == "recommend2")
		{
			int x;
			cin>> x;
			if (x == 1)
			{
				cout << prev(problems.end())->second << '\n';
			}
			else
			{
				cout << problems.begin()->second << '\n';
			}
		}
		else if (cmd == "recommend3")
		{
			int x,l;
			cin >> x>>l;
			if (x == 1)
			{
				auto itr = problems.upper_bound({ l,0 });
				if (itr == problems.end())
					cout << -1 << '\n';
				else
					cout << itr->second << '\n';
			}
			else
			{
				auto itr = problems.lower_bound({ l,0 });
				if (itr == problems.begin())
					cout << -1 << '\n';
				else
					cout << prev(itr)->second << '\n';
			}
		}
	}
}