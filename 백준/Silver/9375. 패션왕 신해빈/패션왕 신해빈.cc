#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <list>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int T, n;
unordered_map<string, int> m1;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--)
	{
		m1.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			if (m1.find(s2) != m1.end())
				m1[s2]++;
			else
				m1[s2] = 1;
		}
		vector<int> v1;
		for (auto t : m1)
		{
			v1.push_back(t.second);
		}
		int sum=1;
		for (int num : v1)
			sum *= (num+1);
		cout << sum - 1 << '\n';
	}

}
