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

int K, L;
unordered_map<string, int> order;

struct cmd {
	bool operator()(pair<string,int> a, pair<string,int> b) {
		return a.second < b.second;
	}
};


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> K >> L;
	for (int i = 0; i < L; i++)
	{
		string t;
		cin >> t;
		order[t] = i;
	}
	vector<pair<string, int>> q(order.begin(), order.end());
	sort(q.begin(), q.end(), cmd());
	for (int i = 0; i < (K>q.size()?q.size():K); i++)
		cout << q[i].first<<'\n';
}