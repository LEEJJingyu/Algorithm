#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;

vector<pair<int,int>> tree;
vector<int> arr;
int N,M;
void init(int node, int start, int end)
{
	if (start == end)
		tree[node] = { arr[start],arr[start] };
	else {
		int mid = (start + end) / 2;
		init(2 * node, start, mid);
		init(2 * node + 1, mid + 1, end);
		tree[node].first = min(tree[node * 2].first, tree[node * 2 + 1].first);
		tree[node].second = max(tree[node * 2].second, tree[node * 2 + 1].second);
	}
}
pair<int, int> query(int node, int start,int end,int L,int R)
{
	if (L > end || R < start)return { 1e9,0 };
	if (L <= start && R >= end)return tree[node];
	int mid = (start + end) / 2;
	pair<int, int> leftV = query(2 * node, start, mid, L, R);
	pair<int, int> rightV = query(2 * node + 1, mid + 1, end, L, R);
	return { min(leftV.first,rightV.first),max(leftV.second,rightV.second) };
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	tree.resize(4 * N);
	arr.resize(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	init(1, 0, N - 1);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		auto ans = query(1, 0, N - 1, a-1, b-1);
		cout << ans.first << ' ' << ans.second << '\n';
	}
}
