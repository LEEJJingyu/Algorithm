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

string S;
unordered_set<string> s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> S;
	for (int i=0;i<S.length();i++)
	{
		for (int len = 1; i + len <= S.length(); len++)
		{
			s.insert(S.substr(i, len));
		}
	}
	cout << s.size();
}
