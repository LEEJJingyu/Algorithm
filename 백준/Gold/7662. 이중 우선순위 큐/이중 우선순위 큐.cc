#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <list>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <unordered_map>
using namespace std;
int T;
int N;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		multiset<int> q;
		for (int i = 0; i < N; i++)
		{
			char cmd;
			int num;
			cin >> cmd >> num;
			if (cmd == 'I')
				q.insert(num);
			else {
				if (q.empty())continue;
				if (num == 1) {
					q.erase(prev(q.end()));
				}
				else
					q.erase(q.begin());
			}
		}
		if (q.empty())
			cout << "EMPTY" << '\n';
		else {
			cout << *prev(q.end()) << ' ' << *q.begin() << '\n';
		}
	}
}