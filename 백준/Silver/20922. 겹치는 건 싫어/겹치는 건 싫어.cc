#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <list>
#include <algorithm>
#include <unordered_map>
using namespace std;

int N, K;
int arr[200000];
int cnt[100001];
int mx = 0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int ed = 0;
	for (int st = 0; st < N; st++)
	{
		while (ed<N&&cnt[arr[ed]] < K)
		{
			cnt[arr[ed]]++;
			ed++;
		}
		mx = max(mx, ed - st);
		cnt[arr[st]]--;
	}
	cout << mx;
}