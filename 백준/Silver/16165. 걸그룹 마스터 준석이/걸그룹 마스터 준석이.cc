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
int N, M;
unordered_map<string, vector<string>> groupN;
unordered_map<string, string> personN;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string group;
		cin >> group;
		int memNum;
		cin >> memNum;
		groupN[group].resize(memNum);
		for (int j = 0; j < memNum; j++)
		{
			string name;
			cin >> name;
			groupN[group][j]=name;
			personN[name] = group;
		}
		sort(groupN[group].begin(), groupN[group].end());
	}
	for (int i = 0; i < M; i++)
	{
		string ans;
		bool isgroup;
		cin >> ans;
		cin >> isgroup;
		if (isgroup)
		{
			cout << personN[ans] << '\n';
		}
		else
		{
			for (string s : groupN[ans])
				cout << s << '\n';
		}
	}
}
