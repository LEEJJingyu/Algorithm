#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <list>
#include <algorithm>
using namespace std;
int N,d,k,c;
int arr[60001];
bool cnt[3001] = {0,};
int mx = 0;
bool chck[3001];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N>>d>>k>>c;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		arr[i + N] = arr[i];
	}
	for (int st = 0; st < N; st++)
	{
		bool isfree = false;
		memset(cnt, 0, sizeof(cnt));
		int length = 0;
		for (int i = 0; i < k; i++)
		{
			if (!cnt[arr[i+st]]) {
				if (arr[i + st] == c)isfree = true;
				length++;
				cnt[arr[i + st]] = true;
			}
		}
		mx = max(length-isfree+1,mx);
	}
	cout << mx;
}
