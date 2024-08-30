#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <list>
#include <algorithm>
using namespace std;
int N, K;
int S[1000001];
int cnt = 0;
int mx = 0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> S[i];
	int ed = 0;
	for (int st = 0; st < N; st++)
	{
		while (ed < N&&cnt<K)
		{
			if (S[ed] % 2) {
				cnt++;
			}
			ed++;
		}
		while (ed<N&&S[ed] % 2 == 0)
		{
			ed++;
		}
		mx = max(ed - st - cnt, mx);
		if (ed == N)break;
		if (S[st] % 2)cnt--;
	}
	cout << mx;
}
