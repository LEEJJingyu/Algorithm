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
	int idx,s, e;
};

vector<Query> query;
vector<int> arr;
int cnt[1000001] = {0};
int cnt_cnt[1000001] = {0};
int ans[100001];
int mx = 0;


bool Comp(Query A, Query B) {
	if (A.s / sqrtN == B.s / sqrtN) {
		return (A.e < B.e);
	}
	return (A.s / sqrtN < B.s / sqrtN);
}
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
	sort(query.begin(), query.end(),Comp);

	int s = query[0].s, e = query[0].e;
	for (int i = s; i <= e; i++) {
		int cur = arr[i];
		cnt_cnt[cnt[cur]]--;
		cnt[cur]++;
		mx = max(mx, cnt[cur]);
		cnt_cnt[cnt[cur]]++;
	}
	ans[query[0].idx] = mx;
	for (int i = 1; i < M; i++) {
		while (s < query[i].s) {
			int cur = arr[s++];
			cnt_cnt[cnt[cur]]--;
			if ((cnt_cnt[cnt[cur]] == 0) && (mx == cnt[cur]))mx--;
			cnt[cur]--;
			cnt_cnt[cnt[cur]]++;
		}
		while (s > query[i].s) {
			int cur = arr[--s];
			cnt_cnt[cnt[cur]]--;
			cnt[cur]++;
			mx = max(mx, cnt[cur]);
			cnt_cnt[cnt[cur]]++;
		}
		while (e < query[i].e) {
			int cur = arr[++e];
			cnt_cnt[cnt[cur]]--;
			cnt[cur]++;
			mx = max(mx, cnt[cur]);
			cnt_cnt[cnt[cur]]++;
		}
		while (e > query[i].e) {
			int cur = arr[e--];
			cnt_cnt[cnt[cur]]--;
			if ((cnt_cnt[cnt[cur]] == 0) && (mx == cnt[cur]))mx--;
			cnt[cur]--;
			cnt_cnt[cnt[cur]]++;
		}
		ans[query[i].idx] = mx;
	}
	for (int i = 0; i < M; i++) cout << ans[i] << "\n";
}