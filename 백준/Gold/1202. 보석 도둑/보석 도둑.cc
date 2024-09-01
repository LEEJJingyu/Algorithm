#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <string>
#include <list>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <map>
#include <unordered_map>
using namespace std;
int N, K;
int C;
pair<int,int> jewel[300000];
multiset<int> bag;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> jewel[i].second >> jewel[i].first;
	sort(jewel, jewel + N,greater<>());
	for (int i = 0; i < K; i++)
	{
		cin >> C;
		bag.insert(C);
	}
	long long sum = 0;
	for (int i = 0; i < N; i++)
	{
		int v, m;
		tie(v, m) = jewel[i];
		auto it = bag.lower_bound(m);
		if (it == bag.end())continue;
		sum += v;
		bag.erase(it);
	}

	cout << sum;
}