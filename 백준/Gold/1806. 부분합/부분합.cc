#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <list>
#include <algorithm>
using namespace std;
int N, S;
int arr[100001];
int mn = 0x7fffffff;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> N>> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	int ed = 0;
	int sum = arr[0];
	for (int st = 0; st < N; st++)
	{

		while (ed < N && sum < S) {
			ed++;
			sum += arr[ed];
		}
		if (ed == N)break;
		if (ed - st+1 < mn) {
			mn = ed - st+1;
		}
		sum -= arr[st];
	}
	if (mn == 0x7fffffff)cout << 0;
	else
		cout << mn;
}
