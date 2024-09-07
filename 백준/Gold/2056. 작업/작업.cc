#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <tuple>
#include <queue>
#include <cmath>
#include <set>
#include<map>
#include<stack>
#include <algorithm>
using namespace std;

int N;
int arr[10001];
int ans[10001];
int cnt[10001];
int sub[10001] = {0};
vector<int> arr2[10001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int cost, n;
		cin >> cost >> n;
		arr[i] = cost;
		cnt[i]=n;
		while (n--)
		{
			int a;
			cin >> a;
			arr2[a].push_back(i);
		}
	}
	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (cnt[i] == 0) {
			ans[i] = arr[i];
			q.push(i);
		}
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (int nxt : arr2[cur])
		{
			cnt[nxt]--;
			sub[nxt] = max(sub[nxt], ans[cur]);
			if (cnt[nxt] == 0)
			{
				ans[nxt] = max(ans[nxt], arr[nxt] +sub[nxt]);
				q.push(nxt);
			}
		}
	}
	int mx = 0;
	for (int i = 1; i <= N; i++) {
		mx = max(mx, ans[i]);
	}
	cout << mx;
}
