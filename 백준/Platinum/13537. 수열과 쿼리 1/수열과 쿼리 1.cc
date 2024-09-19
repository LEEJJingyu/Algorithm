#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <tuple>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;


int N, M;
int arr[100001];
vector<int> tree[1 << 18];


vector<int> *init(int node, int st,int ed)
{
	if (st == ed) {
		tree[node].push_back(arr[st]);
		return &tree[node];
	}
	vector<int>* left = init(node * 2, st, (st + ed) >> 1);
	vector<int>*right = init(node * 2 + 1, ((st + ed) >> 1) + 1, ed);
	tree[node].resize(left->size() + right->size());
	merge(left->begin(), left->end(), right->begin(), right->end(), tree[node].begin());
	return &tree[node];
}

int cnt(int node, int st, int ed ,int L, int R, int index) {
	if (L > ed || R < st)return 0;
	if (L <= st && ed <= R) {
		return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), index);
	}
	return cnt(node * 2, st, (st + ed) >> 1, L, R, index) + cnt(node * 2 + 1, ((st + ed) >> 1)+1, ed, L, R, index);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++) 
		cin >> arr[i];
	init(1, 1, N);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int u, v, k;
		cin >> u >> v >> k;
		cout << cnt(1, 1, N, u, v, k)<<'\n';
	}
}