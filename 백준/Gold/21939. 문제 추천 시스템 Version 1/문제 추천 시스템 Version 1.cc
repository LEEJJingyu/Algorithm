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
multiset<pair<int,int>> problem;
unordered_map<int, int> problems;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int num, level;
		cin >> num >> level;
		problem.insert({ level,num });
		problems[num] = level;
	}
	cin >> P;
	for (int i = 0; i < P; i++)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "add")
		{
			int pm, L;
			cin >> pm >> L;
			problem.insert({ L,pm });
			problems[pm] = L;
		}
		else if (cmd == "recommend")
		{
			int x;
			cin >> x;
			if (x == 1)
				cout<<prev(problem.end())->second<<'\n';
			else
				cout << problem.begin()->second << '\n';
		}
		else if (cmd == "solved")
		{
			int pm;
			cin >> pm;
			problem.erase({ problems[pm],pm });
		}
	}
}