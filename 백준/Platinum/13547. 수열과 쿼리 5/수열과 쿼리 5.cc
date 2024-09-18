#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <tuple>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

int sqrtN;
int N,M;
struct Query {
	int idx, s, e;
	bool operator < (Query& x) {
		if (s / sqrtN != x.s / sqrtN) return s / sqrtN < x.s / sqrtN;
		return e < x.e;
	}
};

vector<Query> query;
vector<int> arr;
int cnt[1000001];
int ans[100001];
int res = 0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	sqrtN = sqrt(N);
	arr.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	cin >> M;
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		query.push_back({ i, s, e });
	}
	sort(query.begin(), query.end());

	int s = query[0].s, e = query[0].e;
	for (int i = s; i <= e; i++) {
		if (cnt[arr[i]] == 0)
			res++;
		cnt[arr[i]]++;
	}
	ans[query[0].idx] = res;

	for (int i = 1; i < M; i++) {
		while (s < query[i].s) {
			cnt[arr[s]]--;
			if (cnt[arr[s++]] == 0)
				res--;
		}
		while (s > query[i].s) {
			if (cnt[arr[--s]] == 0)
				res++;
			cnt[arr[s]]++;
		}
		while (e < query[i].e) {
			if (cnt[arr[++e]] == 0)
				res++;
			cnt[arr[e]]++;
		}
		while (e > query[i].e) {
			cnt[arr[e]]--;
			if (cnt[arr[e--]] == 0)
				res--;
		}
		ans[query[i].idx] = res;
	}
	for (int i = 0; i < M; i++) cout << ans[i] << "\n";
}