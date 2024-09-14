#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <tuple>
#include <queue>
#include <cmath>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;
int C, N, Q;

int arr[4000005][26] = {0};
bool color[4000005] = {0};
unordered_map<string, bool> nick;
int unused = 2;
void insert(string s)
{
	int cur = 1;
	for (char c : s)
	{
		if (arr[cur][c - 'a'] == 0)
			arr[cur][c - 'a'] = unused++;
		cur = arr[cur][c - 'a'];
	}
	color[cur] = true;
}
bool find(string s, bool iscolor)
{
	int cur=1;
	for (int i=0;i<s.size();i++)
	{
		char c = s[i];
		if (arr[cur][c - 'a'] == 0)
			return false;
		cur = arr[cur][c - 'a'];
		if (iscolor && color[cur]) {
			if (nick[s.substr(i+1,s.size()-i-1)])
				return true;
		}
	}
	return false;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> C >> N;
	for (int i = 0; i < C; i++)
	{
		string s;
		cin >> s;
		insert(s);
	}
	while (N--)
	{
		string s;
		cin >> s;
		nick[s] = true;
	}
	cin >> Q;
	while (Q--)
	{
		string s;
		cin >> s;
		cout << (find(s,true) ? "Yes" : "No") << '\n';
	}
}