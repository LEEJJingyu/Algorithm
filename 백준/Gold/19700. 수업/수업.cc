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

int N;
pair<int, int> students[500001];
multiset<int> classG;
int ln = 0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> students[i].first >> students[i].second;
	sort(students, students + N, greater<>());
	for (int i = 0; i < N; i++)
	{
		auto itr = classG.lower_bound(1-students[i].second);
		if (itr == classG.end())
		{
			classG.insert(-1);
		}
		else {
			int val = *itr;
			classG.erase(itr);
			classG.insert(val - 1);
		}
	}
	cout << classG.size();
}