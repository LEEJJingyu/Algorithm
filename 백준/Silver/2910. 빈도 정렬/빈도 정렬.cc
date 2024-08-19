#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> order;

int cmp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return order[a.second] < order[b.second];

	return a.first > b.first;
}

map<int, int> m;
map<int, int>::iterator it;
int N,C;
int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> C;
	vector<pair<int, int > > v;
	vector<int> answer;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		m[num]++;
		if (order[num] == 0) order[num] = i + 1;
	}

	for (it = m.begin(); it != m.end(); it++) {
		v.push_back({ it->second, it->first });
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].first; j++) {
			answer.push_back(v[i].second);
		}
	}

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << " ";
	}
}