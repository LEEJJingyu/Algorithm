#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <list>
#include <algorithm>
#include <unordered_map>
using namespace std;
int N, M;

pair<int, int> arr[1000000];
int cnt[1000] = {0};
int mn=(1 << 30);
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N*M; i++){
		int t;
		cin >> t;
		arr[i] = { t,i/M };
	}
	sort(arr, arr + N * M);
	
	int ed = 0;
	int length = 0;
	for (int st = 0; st < N * M; st++)
	{
		if (ed == N * M)break;
		while (length < N&&ed<N*M)
		{
			if (cnt[arr[ed].second] == 0)
				length++;
			cnt[arr[ed].second]++;
			ed++;
		}
		while (cnt[arr[st].second] > 1)
		{
			cnt[arr[st].second]--;
			st++;
		}
		if (length < N)break;
		mn = min(arr[ed-1].first - arr[st].first, mn);

		cnt[arr[st].second]--;
		if (cnt[arr[st].second] == 0)length--;
	}
	cout << mn;
}