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
		tree[node] = tree[2 * node] + tree[2 * node + 1];
	}
}
long long query(int node, int start, int end, int L, int R) {
	if (L > end || R < start)return 0;
	if (L <= start && R >= end)return tree[node];
	int mid = (start + end) / 2;
	return query(2 * node, start, mid, L, R) + query(2 * node + 1, mid + 1, end, L, R);
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
		tree[node] = tree[2 * node] + tree[2 * node + 1];
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M >> K;
	arr.resize(N + 1);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	tree.resize(arr.size() * 4);
	buildTree(1, 0, N - 1);
	for (int i = 0; i < M + K; i++)
	{
		int cmd, a;
		long long b;
		cin >> cmd >> a >> b;
		if (cmd == 1)
			update(1,0, N -1,a-1, b);
		else
			cout << query(1,0, N -1,a-1, b-1) << '\n';
	}
}