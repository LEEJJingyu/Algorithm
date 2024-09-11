#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, K;
vector<long long> arr;
vector<long long> tree;
int n;
void buildTree(int node, int start, int end) {
	if (start == end)
		tree[node] = arr[start];
	else {
		int mid = (start + end) / 2;
		buildTree(2 * node, start, mid);
		buildTree(2 * node + 1, mid + 1, end);
		tree[node] = tree[2 * node] * tree[2 * node + 1];
		tree[node] %= 1000000007;
	}
}
long long query(int node, int start, int end, int L, int R) {
	if (L > end || R < start)return 1;
	if (L <= start && R >= end)return tree[node];
	int mid = (start + end) / 2;
	return (query(2 * node, start, mid, L, R) * query(2 * node + 1, mid + 1, end, L, R)) % 1000000007;
}
void update(int node, int start, int end, int idx, long long val) {
	if (start == end)
		tree[node] = val;
	else {
		int mid = (start + end) / 2;
		if (start <= idx && idx <= mid)
			update(2 * node, start, mid, idx, val);
		else
			update(2 * node + 1, mid + 1, end, idx, val);
		tree[node] = tree[2 * node] * tree[2 * node + 1];
		tree[node] %=1000000007;
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	tree.resize(N * 4);
	buildTree(1,0,N-1);
	for (int i = 0; i < M + K; i++)
	{
		int type;
		cin >> type;
		if (type == 1){
			int idx;
			long long val;
			cin >> idx >> val;
			update(1, 0, N - 1, idx-1, val);
		}
		else {
			int L, R;
			cin >> L >> R;
			cout << query(1, 0, N - 1, L-1, R-1)%1000000007<<'\n';
		}
	}
}