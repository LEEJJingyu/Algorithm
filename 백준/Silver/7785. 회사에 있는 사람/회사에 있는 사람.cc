#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <list>
#include <algorithm>
#include <unordered_set>
using namespace std;

unordered_set<string> v1;
vector<string> v2;
int N;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string s,cmd;
		cin >> s >> cmd;
		if (cmd == "enter")
			v1.insert(s);
		else
			v1.erase(s);
	}
	for (string s : v1) {
		v2.push_back(s);
	}
	sort(v2.begin(), v2.end(),greater<>());
	for (string s : v2)
		cout << s << '\n';
}