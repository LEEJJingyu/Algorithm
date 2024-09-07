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

int T;

int N, K;
vector<int> arr[1001];
int cnt[1001] = {0};
int cst[1001];
int sub[1001] = {0};
int ans[1001] = { 0 };

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> K;
		fill(sub + 1, sub + N + 1, 0);
		
		for (int i = 1; i <= N; i++) {
			arr[i].clear();
			cin >> cst[i];
		}
		while (K--)
		{
			int a, b;
			cin >> a >> b;
			arr[a].push_back(b);
			cnt[b]++;
		}
		int target;
		cin >> target;
		queue<int> q;
		for (int i = 1; i <= N; i++)
			if (!cnt[i]) {
				q.push(i);
				ans[i] = cst[i];
			}
		while (!q.empty())
		{
			int cur = q.front(); q.pop();
			for (int nxt : arr[cur])
			{
				cnt[nxt]--;
				sub[nxt] = max(sub[nxt], ans[cur]);
				if (!cnt[nxt])
				{
					ans[nxt] = cst[nxt] + sub[nxt];
					q.push(nxt);
				}
			}
		}
		cout << ans[target] << '\n';
	}
}
