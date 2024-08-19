#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

string s;
priority_queue<string,vector<string>,greater<string>> v1;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		string tmp = "";
		for (int j=i;j<s.size();j++)
			tmp += s[j];
		v1.push(tmp);
	}
	while (!v1.empty())
	{
		cout << v1.top() << '\n'; v1.pop();
	}
}