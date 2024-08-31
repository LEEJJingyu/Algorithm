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
unordered_map<string, string> m1;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		m1[s1] = s2;
	}
	for (int i = 0; i < M; i++)
	{
		string cmd;
		cin >> cmd;
		cout << m1[cmd] << '\n';
	}
}