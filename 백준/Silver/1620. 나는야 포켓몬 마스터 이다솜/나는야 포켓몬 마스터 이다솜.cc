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
unordered_map<string, int> poke;
string poke2[100001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		string s;
		cin >> s;
		poke[s] = i;
		poke2[i] = s;
	}
	for (int i = 0; i < M; i++)
	{
		string s;
		cin >> s;
		if (s[0] > '0' && s[0] <= '9')
			cout << poke2[stoi(s)] << '\n';
		else
			cout << poke[s] << '\n';
	}
}